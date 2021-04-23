package com.example.cooltalks.ViewsFolder;

import android.content.Context;
import android.content.Intent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.bumptech.glide.Glide;
import com.example.cooltalks.Activities.MessagePage;
import com.example.cooltalks.R;
import com.example.cooltalks.Objects.User;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;
import com.example.cooltalks.databinding.ConversationLayoutBinding;

import org.jetbrains.annotations.NotNull;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;

public class UserChatView extends RecyclerView.Adapter<UserChatView.UserViewHolder> {

    Context context;
    ArrayList<User> users;
    public UserChatView(Context context, ArrayList<User> users){
        this.context = context;
        this.users = users;
    }

    @NotNull
    @Override
    public UserViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(context).inflate(R.layout.conversation_layout,parent,true);
        return new UserViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull UserViewHolder holder, int position) {
        User user = users.get(position);

        String friendId = FirebaseAuth.getInstance().getUid();
        String friendRoom = friendId+user.getUserId();
        FirebaseDatabase.getInstance().getReference()
                .child("chats")
                .child(friendRoom)
                .addValueEventListener(new ValueEventListener() {
                    @Override
                    public void onDataChange(@NonNull DataSnapshot snapshot) {
                        if(snapshot.exists()){
                            String RecentMessage = snapshot.child("RecentMessage").getValue(String.class);
                            long time = snapshot.child("RecentMessageTime").getValue(long.class);
                            SimpleDateFormat dateFormat = new SimpleDateFormat("HH:MM");
                            holder.binding.time.setText(dateFormat.format(new Date(time)));
                            holder.binding.chatText.setText(RecentMessage);
                        }else{
                            holder.binding.chatText.setText("Tap to Start Chat");
                        }
                    }

                    @Override
                    public void onCancelled(@NonNull DatabaseError error) {

                    }
                });

        holder.binding.UserName.setText(user.getUserName());

        if(user.getUserGender().equals("male")) {
            Glide.with(context).load(user.getUserProfileImage())
                    .placeholder(R.drawable.avatar)
                    .into(holder.binding.imageView4);
        }else{
            Glide.with(context).load(user.getUserProfileImage())
                    .placeholder(R.drawable.femaleavatar)
                    .into(holder.binding.imageView4);
        }
        holder.itemView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(context, MessagePage.class);
                intent.putExtra("name",user.getUserName());
                intent.putExtra("image",user.getUserProfileImage());
                intent.putExtra("UId",user.getUserId());
                context.startActivity(intent);
            }
        });
    }

    @Override
    public int getItemCount() {
        return users.size();
    }

    public static class UserViewHolder extends RecyclerView.ViewHolder{

        ConversationLayoutBinding binding;

        public UserViewHolder(@NonNull View itemView) {
            super(itemView);
            binding = ConversationLayoutBinding.bind(itemView);

        }
    }
}
