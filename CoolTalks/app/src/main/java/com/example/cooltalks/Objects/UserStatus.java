package com.example.cooltalks.Objects;

import java.util.ArrayList;

public class UserStatus extends Status {
    private String UserName, profileImage;
    private long lastUpdated;
    private ArrayList<UserStatus> statuses;

    public UserStatus() {
    }

    public UserStatus(String UserName, String profileImage, long lastUpdated, ArrayList<UserStatus> statuses) {
        this.UserName = UserName;
        this.profileImage = profileImage;
        this.lastUpdated = lastUpdated;
        this.statuses = statuses;
    }

    public String getUserName() {
        return UserName;
    }

    public void setUserName(String UserName) {
        this.UserName = UserName;
    }

    public String getProfileImage() {
        return profileImage;
    }

    public void setProfileImage(String profileImage) {
        this.profileImage = profileImage;
    }

    public long getLastUpdated() {
        return lastUpdated;
    }

    public void setLastUpdated(long lastUpdated) {
        this.lastUpdated = lastUpdated;
    }

    public ArrayList<UserStatus> getStatuses() {
        return statuses;
    }

    public void setStatuses(ArrayList<UserStatus> statuses) {
        this.statuses = statuses;
    }
}
