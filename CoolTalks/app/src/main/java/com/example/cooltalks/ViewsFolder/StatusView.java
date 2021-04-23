package com.example.cooltalks.ViewsFolder;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;


import com.bumptech.glide.Glide;
import com.example.cooltalks.Activities.MainActivity;
import com.example.cooltalks.Objects.Status;
import com.example.cooltalks.Objects.UserStatus;
import com.example.cooltalks.R;
import com.example.cooltalks.databinding.UserStatusBinding;

import java.util.ArrayList;

import omari.hamza.storyview.StoryView;
import omari.hamza.storyview.callback.StoryClickListeners;
import omari.hamza.storyview.model.MyStory;


public class StatusView extends RecyclerView.Adapter<StatusView.TopStatusViewHolder> {

    Context context;
    ArrayList<UserStatus> userStatuses;

    public StatusView(Context context, ArrayList<UserStatus> userStatuses) {
        this.context = context;
        this.userStatuses = userStatuses;
    }

    @NonNull
    @Override
    public TopStatusViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(context).inflate(R.layout.user_status, parent, false);
        return new TopStatusViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull TopStatusViewHolder holder, int position) {

        UserStatus userStatus = userStatuses.get(position);

        UserStatus lastStatus = userStatus.getStatuses().get(userStatus.getStatuses().size());    // removed -1 here

        Glide.with(context).load(lastStatus.getProfileImage()).into(holder.binding.image);

        holder.binding.circularstoryview.setPortionsCount(userStatus.getStatuses().size());

        holder.binding.circularstoryview.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ArrayList<MyStory> myStories = new ArrayList<>();
                for (Status status : userStatus.getStatuses()) {
                    myStories.add(new MyStory(status.getImageURL()));
                }

                new StoryView.Builder(((MainActivity) context).getSupportFragmentManager())
                        .setStoriesList(myStories) // Required
                        .setStoryDuration(5000) // Default is 2000 Millis (2 Seconds)
                        .setTitleText(userStatus.getUserName()) // Default is Hidden
                        .setSubtitleText("") // Default is Hidden
                        .setTitleLogoUrl(userStatus.getProfileImage()) // Default is Hidden
                        .setStoryClickListeners(new StoryClickListeners() {
                            @Override
                            public void onDescriptionClickListener(int position) {

                            }

                            @Override
                            public void onTitleIconClickListener(int position) {

                            }
                        })
                        .build() // Must be called before calling show method
                        .show();
            }
        });
    }

    @Override
    public int getItemCount() {
        return userStatuses.size();
    }

    public class TopStatusViewHolder extends RecyclerView.ViewHolder {

        UserStatusBinding binding;

        public TopStatusViewHolder(@NonNull View itemView) {
            super(itemView);
            binding = UserStatusBinding.bind(itemView);
        }
    }
}

