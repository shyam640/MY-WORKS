package com.example.birthday;

import android.content.Intent;
import android.media.MediaPlayer;
import android.os.Bundle;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import java.sql.Time;
import java.util.Timer;
import java.util.TimerTask;

public class BlastActivity extends AppCompatActivity {
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
//        Playing audio on activity open
        finishActivity(20);
        MediaPlayer birthday = MediaPlayer.create(BlastActivity.this, R.raw.birthday);
        birthday.start();
        super.onCreate(savedInstanceState);
        setContentView(R.layout.blast);

        // Delaying the next activity to be executed to wait for song finish
        new Timer().schedule(new TimerTask() {

            @Override
            public void run() {
                Intent intent = new Intent(BlastActivity.this, MainActivity.class);
                intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TASK | Intent.FLAG_ACTIVITY_NEW_TASK);
                birthday.stop();                // Song stopped when moving to next activity
                startActivityForResult(intent,30);
            }
        }, 20000);
    }


}
