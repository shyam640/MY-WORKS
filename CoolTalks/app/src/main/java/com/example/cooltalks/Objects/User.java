package com.example.cooltalks.Objects;

import java.util.ArrayList;

public class User extends ArrayList<User> {
    private String UserId,UserName,PhoneNumber,UserProfileImage,UserEmail,UserPassword;
    private String UserGender,UserAboutMe;

    public User() {

    }

    // Press alt+Insert to get constructor or you can right click then click on generate and then select constructor and below code will be automatically loaded .
    // Constructor For Phone Number sign in
    public User(String userId, String userName, String phoneNumber, String userProfileImage, String userGender, String userAboutMe) {
        this.UserId = userId;
        this.UserName = userName;
        this.PhoneNumber = phoneNumber;
        this.UserProfileImage = userProfileImage;
        this.UserGender = userGender;
        UserAboutMe = userAboutMe;
    }

    // Constructor for Email sign in
    public User(String userEmail,String userPassword,String userGender){
        this.UserEmail = userEmail;
        this.UserPassword = userPassword;
        this.UserGender = userGender;
    }


    // Press alt+Insert to get getter and setters or you can right click then click on generate and then getter and setter and below code will be automatically loaded .
    public String getUserId() {
        return UserId;
    }

    public void setUserId(String userId) {
        this.UserId = userId;
    }

    public String getUserName() {
        return UserName;
    }

    public void setUserName(String userName) {
        this.UserName = userName;
    }

    public String getPhoneNumber() {
        return PhoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.PhoneNumber = phoneNumber;
    }

    public String getUserProfileImage() {
        return UserProfileImage;
    }

    public void setUserProfileImage(String userProfileImage) {
        this.UserProfileImage = userProfileImage;
    }

    public String getUserEmail() {
        return UserEmail;
    }

    public void setUserEmail(String userEmail) {
        UserEmail = userEmail;
    }

    public String getUserPassword() {
        return UserPassword;
    }

    public void setUserPassword(String userPassword) {
        UserPassword = userPassword;
    }

    public String getUserGender() {
        return UserGender;
    }

    public void setUserGender(String userGender) {
        UserGender = userGender;
    }

    public String getUserAboutMe() {
        return UserAboutMe;
    }

    public void setUserAboutMe(String userAboutMe) {
        UserAboutMe = userAboutMe;
    }

}
