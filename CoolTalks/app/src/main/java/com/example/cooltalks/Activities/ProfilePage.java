package com.example.cooltalks.Activities;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.app.ProgressDialog;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;

import com.example.cooltalks.Objects.User;
import com.example.cooltalks.databinding.ActivityProfilePageBinding;
import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.storage.FirebaseStorage;
import com.google.firebase.storage.StorageReference;
import com.google.firebase.storage.UploadTask;

import java.util.Date;
import java.util.HashMap;

public class ProfilePage extends AppCompatActivity {
    // Doing binding to just avoid using findViewById again and again
    ActivityProfilePageBinding binding;
    FirebaseAuth auth;                                              // Firebase authorising
    FirebaseDatabase database;                                      // Firebase database authorising
    FirebaseStorage storage;                                        // Firebase storage authorising
    Uri SelectedProfileImage;                                       // Profile image
    ProgressDialog dialog;                                          // Creating loader screen


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityProfilePageBinding.inflate(getLayoutInflater());                  // Doing binding
        setContentView(binding.getRoot());


        // Creating a loader on clicking Save info
        dialog = new ProgressDialog(this);
        dialog.setMessage("Saving Info...");
        dialog.setCancelable(false);

        database = FirebaseDatabase.getInstance();                  // Getting firebase database
        storage = FirebaseStorage.getInstance();                    // Getting firebase storage
        auth = FirebaseAuth.getInstance();                          // Getting firebase authentication

        getSupportActionBar().hide();                       // To hide CoolTalks heading in blue box that comes by default

        // Setting up profile image
        binding.imageView4.setOnClickListener(v -> {                        // In place of " new View.OnClickListener() " we used v->
            Intent intent = new Intent();
            intent.setAction(Intent.ACTION_GET_CONTENT);                // setting action to get image
            intent.setType("image/*");                                  // Setting type to image only
            startActivityForResult(intent,45);
            // Starting activity for intent and request code is random I gave 45 u can give any
        });

        // Setting click Listener over button save info
        binding.SaveInfo.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String name = binding.UserNameBox.getText().toString();             // Getting name from UserNameBox
                if(name.isEmpty()){                                                 // Checking if name is filled or not
                    binding.UserNameBox.setError("Please Enter a Name !");              // If name not entered then showing this error
                    return;
                }
                                         // In place of " new View.OnClickListener() " we used v->

            dialog.show();
            if(SelectedProfileImage != null){
                StorageReference ref = storage.getReference().child("Profiles").child(auth.getUid());
                // First child creates a folder on firebase and second child add user id to the folder
                // Putting selected image to firebase storage
                ref.putFile(SelectedProfileImage).addOnCompleteListener(new OnCompleteListener<UploadTask.TaskSnapshot>() {
                    @Override
                    public void onComplete(@NonNull Task<UploadTask.TaskSnapshot> task) {
                        if(task.isSuccessful()){                                    // If uploading is successful
                            ref.getDownloadUrl().addOnSuccessListener(new OnSuccessListener<Uri>() {        // creating download link
                                @Override
                                public void onSuccess(Uri uri) {
                                    String imageURL = uri.toString();          // Changing url of image to string and storing in imageURL
                                    String UId = auth.getUid();                                        // Getting User id
                                    String UserPhone = auth.getCurrentUser().getPhoneNumber();         // Getting User phone number
                                    String name = binding.UserNameBox.getText().toString();             // Getting User Name
                                    String gender = getIntent().getStringExtra("gender");
                                    // I did some mistake here but not getting what?????
                                    String userAboutMe = binding.AboutMe.getText().toString();


                                    User user = new User(UId,name,UserPhone,imageURL,gender, userAboutMe);
                                    // Creating object to data collected
                                    database.getReference()
                                            .child("users")
                                            .child(user.getUserId())
//                           Above child is to be used importantly because if we don't use it we will override data each time we login as new user
                                            .setValue(user)
                                            .addOnSuccessListener(new OnSuccessListener<Void>() {
                                                @Override
                                                public void onSuccess(Void aVoid) {
                                                    dialog.dismiss();
                                                    // Starting main activity on everything successful
                                                    Intent intent = new Intent(ProfilePage.this,MainActivity.class);
                                                    startActivity(intent);
                                                    finish();
                                                }
                                            });

                                }
                            });
                        }
                    }
                });

            }else {
                String UId = auth.getUid();
                String UserPhone = auth.getCurrentUser().getPhoneNumber();
                String gender = getIntent().getStringExtra("gender");
                String userAboutMe = binding.AboutMe.getText().toString();
                User user1 = new User();
                User user = new User(UId,name,UserPhone,"No Image",gender, userAboutMe);
//                if(gender){
//                    user = new User(UId, name, UserPhone, "@drawable/femaleavatar",gender);
//                }
//                else if(gender.equals("male")){
//                    user = new User(UId, name, UserPhone,"@drawable/avatar",gender);
//                }
                database.getReference()
                        .child("persons/users")
                        .child(UId)
                        .push()
                        .setValue(user)
                        .addOnSuccessListener(new OnSuccessListener<Void>() {
                            @Override
                            public void onSuccess(Void aVoid) {
                                dialog.dismiss();
                                Intent intent = new Intent(ProfilePage.this, MainActivity.class);
                                startActivity(intent);
                                finish();
                            }
                        });
            }
            }
        });

    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if(data!=null){
            if(data.getData()!=null){
                Uri uri = data.getData();
                FirebaseStorage storage = FirebaseStorage.getInstance();
                long time = new Date().getTime();
                StorageReference reference = storage.getReference().child("Profiles").child(time+"");
                reference.putFile(uri).addOnCompleteListener(new OnCompleteListener<UploadTask.TaskSnapshot>() {
                    @Override
                    public void onComplete(@NonNull Task<UploadTask.TaskSnapshot> task) {
                        if(task.isSuccessful()){
                            reference.getDownloadUrl().addOnSuccessListener(new OnSuccessListener<Uri>() {
                                @Override
                                public void onSuccess(Uri uri) {
                                    String filePath = uri.toString();
                                    HashMap<String,Object> obj = new HashMap<>();
                                    obj.put("image",filePath);
                                    database.getReference().child("persons/users").child(FirebaseAuth.getInstance().getUid())
                                            .updateChildren(obj).addOnSuccessListener(new OnSuccessListener<Void>() {
                                        @Override
                                        public void onSuccess(Void aVoid) {

                                        }
                                    });
                                }
                            });
                        }
                    }
                });
                binding.imageView4.setImageURI(data.getData());
                SelectedProfileImage = data.getData();        // saving url to image in SelectedProfileImage
            }
        }

    }
}