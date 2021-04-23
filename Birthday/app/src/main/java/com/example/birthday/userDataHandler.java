package com.example.birthday;

public class userDataHandler {
    String name,message;

    public userDataHandler(){

    }

    // Getting name and message
    public userDataHandler(String name, String message) {
        this.name = name;
        this.message = message;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }
}
