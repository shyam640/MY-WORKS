    package com.example.cooltalks.Activities;

    import android.app.ProgressDialog;
    import android.content.Intent;
    import android.net.Uri;
    import android.os.Bundle;
    import android.view.Menu;
    import android.view.MenuItem;
    import android.widget.LinearLayout;
    import android.widget.Toast;

    import androidx.annotation.NonNull;
    import androidx.annotation.Nullable;
    import androidx.appcompat.app.AppCompatActivity;
    import androidx.recyclerview.widget.LinearLayoutManager;
    import androidx.recyclerview.widget.RecyclerView;

    import com.example.cooltalks.Objects.Status;
    import com.example.cooltalks.Objects.UserStatus;
    import com.example.cooltalks.R;
    import com.example.cooltalks.Objects.User;
    import com.example.cooltalks.ViewsFolder.StatusView;
    import com.example.cooltalks.ViewsFolder.UserChatView;
    import com.example.cooltalks.databinding.ActivityMainBinding;
    import com.google.android.gms.tasks.OnCompleteListener;
    import com.google.android.gms.tasks.OnSuccessListener;
    import com.google.android.gms.tasks.Task;
    import com.google.android.material.bottomnavigation.BottomNavigationView;
    import com.google.firebase.auth.FirebaseAuth;
    import com.google.firebase.database.DataSnapshot;
    import com.google.firebase.database.DatabaseError;
    import com.google.firebase.database.FirebaseDatabase;
    import com.google.firebase.database.ValueEventListener;
    import com.google.firebase.storage.FirebaseStorage;
    import com.google.firebase.storage.StorageReference;
    import com.google.firebase.storage.UploadTask;

    import java.util.ArrayList;
    import java.util.Date;
    import java.util.HashMap;

    public class MainActivity extends AppCompatActivity {

        ActivityMainBinding binding;                            // Doing binding
        FirebaseDatabase database;                              // Firebase database attaching
        ArrayList<User> users;
        UserChatView userChatView;
        StatusView statusView;
        ArrayList<UserStatus> usersStatus;
        ProgressDialog dialog;
        User user;
        FirebaseAuth auth;
        ProgressDialog dialog1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        dialog = new ProgressDialog(this);
        dialog.setMessage("Uploading Image...");
        dialog.setCancelable(true);


        dialog1 = new ProgressDialog(this);
        dialog1.setTitle("CoolTalks says...");
        dialog1.setMessage("Signing out...");
        dialog1.setCancelable(false);

        auth = FirebaseAuth.getInstance();
        database = FirebaseDatabase.getInstance();

        users = new ArrayList<>();
        usersStatus = new ArrayList<>();

        database.getReference().child("users").child(FirebaseAuth.getInstance().getUid()).push().addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                user = snapshot.getValue(User.class);
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {

            }
        });

        userChatView = new UserChatView(this,users);
        statusView = new StatusView(this,usersStatus);
//        binding.recyclerView.setLayoutManager(new LinearLayoutManager(this));

        LinearLayoutManager layoutManager = new LinearLayoutManager(this);
        layoutManager.setOrientation(RecyclerView.HORIZONTAL);
        binding.statusList.setLayoutManager(layoutManager);
        binding.statusList.setAdapter(statusView);
        binding.statusList.showShimmerAdapter();

        binding.recyclerView.setAdapter(userChatView);
        LinearLayoutManager layoutManager1 = new LinearLayoutManager(this);
        layoutManager1.setOrientation(RecyclerView.VERTICAL);
        binding.recyclerView.setAdapter(userChatView);
        binding.recyclerView.showShimmerAdapter();


        database.getReference().child("users").push().addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                users.clear();
                for(DataSnapshot snapshot1 : snapshot.getChildren()){
                    User user = snapshot1.getValue(User.class);
                    if(user.getUserId().equals(FirebaseAuth.getInstance().getUid())) {
                        users.add(user);
                    }
                }
                binding.recyclerView.hideShimmerAdapter();
                userChatView.notifyDataSetChanged();
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {

            }
        });

        database.getReference().child("stories").push().addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                if(snapshot.exists()) {
                    usersStatus.clear();
                    for(DataSnapshot storySnapshot : snapshot.getChildren()) {
                        UserStatus status = new UserStatus();
                        status.setUserName(storySnapshot.child("name").getValue(String.class));
                        status.setProfileImage(storySnapshot.child("profileImage").getValue(String.class));
                        status.setLastUpdated(storySnapshot.child("lastUpdated").getValue(Long.class));

                        ArrayList<UserStatus> statuses = new ArrayList<>();

                        for(DataSnapshot statusSnapshot : storySnapshot.child("statuses").getChildren()) {
                            UserStatus sampleStatus = statusSnapshot.getValue(UserStatus.class);
                            statuses.add(sampleStatus);
                        }

                        status.setStatuses(statuses);
                        usersStatus.add(status);
                    }
                    binding.statusList.hideShimmerAdapter();
                    statusView.notifyDataSetChanged();
                }
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {

            }
        });


        binding.bottomNavigationView.setOnNavigationItemSelectedListener(new BottomNavigationView.OnNavigationItemSelectedListener() {
            @Override
            public boolean onNavigationItemSelected(@NonNull MenuItem item) {
                switch (item.getItemId()) {
                    case R.id.status:
                        Intent intent = new Intent();
                        intent.setType("image/*");
                        intent.setAction(Intent.ACTION_GET_CONTENT);
                        startActivityForResult(intent, 75);
                        break;

                    case R.id.calls:
                        Toast.makeText(MainActivity.this, "This feature will be available in next update !", Toast.LENGTH_SHORT).show();
                        break;
                }
                return false;
            }
        });
    }

        @Override
        protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
            super.onActivityResult(requestCode, resultCode, data);

            if(data != null) {
                if(data.getData() != null) {
                    dialog.show();
                    FirebaseStorage storage = FirebaseStorage.getInstance();
                    Date date = new Date();
                    StorageReference reference = storage.getReference().child("Status").child(date.getTime() + "");

                    reference.putFile(data.getData()).addOnCompleteListener(new OnCompleteListener<UploadTask.TaskSnapshot>() {
                        @Override
                        public void onComplete(@NonNull Task<UploadTask.TaskSnapshot> task) {
                            if(task.isSuccessful()) {
                                reference.getDownloadUrl().addOnSuccessListener(new OnSuccessListener<Uri>() {
                                    @Override
                                    public void onSuccess(Uri uri) {
                                        UserStatus userStatus = new UserStatus();
                                        userStatus.setStatuses(userStatus.getStatuses());
                                        userStatus.setProfileImage(userStatus.getProfileImage());
                                        userStatus.setLastUpdated(date.getTime());

                                        HashMap<String, Object> obj = new HashMap<>();
                                        obj.put("name", userStatus.getUserName());
                                        obj.put("profileImage", userStatus.getProfileImage());
                                        obj.put("lastUpdated", userStatus.getLastUpdated());

                                        String imageUrl = uri.toString();
                                        UserStatus status = new UserStatus(userStatus.getUserName(),imageUrl, userStatus.getLastUpdated(),userStatus.getStatuses());

                                        database.getReference()
                                                .child("stories")
                                                .child(FirebaseAuth.getInstance().getUid())
                                                .updateChildren(obj);

                                        database.getReference().child("stories")
                                                .child(FirebaseAuth.getInstance().getUid())
                                                .child("statuses")
                                                .push()
                                                .setValue(status);

                                        dialog.dismiss();
                                    }
                                });
                            }
                        }
                    });
                }
            }
        }

        @Override
        protected void onResume() {
            super.onResume();
            database.getReference().child("presence").child(auth.getCurrentUser().getUid()).setValue("Online");
        }

        @Override
        protected void onPause() {
            super.onPause();
            database.getReference().child("presence").child(auth.getCurrentUser().getUid()).setValue("Offline");
        }

        @Override
        public boolean onOptionsItemSelected(@NonNull MenuItem item) {
            switch (item.getItemId()) {
                case R.id.newgroup:
                    Intent intent = new Intent(MainActivity.this,GroupChatActivity.class);
                    startActivity(intent);
                    break;
                case R.id.qrcode:
                    Toast.makeText(this, "QR Code feature will be available soon !", Toast.LENGTH_SHORT).show();
                    break;
                case R.id.invite:
                    Toast.makeText(this, "Invite Feature will be available soon !", Toast.LENGTH_SHORT).show();
                    break;
                case R.id.search:
                    Toast.makeText(this, "Search feature will be available soon !", Toast.LENGTH_SHORT).show();
                    break;
                case R.id.settings:
                    Toast.makeText(this, "Settings feature will be available soon !", Toast.LENGTH_SHORT).show();
                    break;
                case R.id.logout:
                    auth.signOut();
                    dialog1.show();
                    Intent intent1 = new Intent(MainActivity.this,LoginPage.class);
                    startActivity(intent1);
                    dialog1.dismiss();
                    finish();
                    break;
            }
            return super.onOptionsItemSelected(item);
        }

        @Override
        public boolean onCreateOptionsMenu(Menu menu) {
            getMenuInflater().inflate(R.menu.topmenu, menu);
            return super.onCreateOptionsMenu(menu);
        }

    }