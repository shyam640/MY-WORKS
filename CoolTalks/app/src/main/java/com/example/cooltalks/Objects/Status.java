package com.example.cooltalks.Objects;

public class Status {
    private String imageURL;
    private long timeSent;

    public Status() {
    }

    public Status(String imageURL, long timeSent) {
        this.imageURL = imageURL;
        this.timeSent = timeSent;
    }

    public String getImageURL() {
        return imageURL;
    }

    public void setImageURL(String imageURL) {
        this.imageURL = imageURL;
    }

    public long getTimeSent() {
        return timeSent;
    }

    public void setTimeSent(long timeSent) {
        this.timeSent = timeSent;
    }
}
