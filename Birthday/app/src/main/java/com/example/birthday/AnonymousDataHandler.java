package com.example.birthday;

public class AnonymousDataHandler {
    String message;
    public AnonymousDataHandler(){

    }

    public AnonymousDataHandler(String message) {
        this.message = message;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }
}
