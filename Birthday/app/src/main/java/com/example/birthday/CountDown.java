package com.example.birthday;

import android.Manifest;
import android.content.Intent;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.os.Handler;
import android.widget.TextView;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;

import java.sql.Time;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.SimpleTimeZone;
import java.util.Timer;
import java.util.TimerTask;

public class CountDown extends AppCompatActivity {
    TextView text1;                 // Variable to store seconds to display
    private static final String FORMAT = "%02d";        // format of time displaying
    private Handler handler;
    private Runnable runnable;


    // I might have done binding to just reduce the use of findViewById again and again
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.countdown_timer);
        ActivityCompat.requestPermissions(CountDown.this,
                new String[]{Manifest.permission.WRITE_EXTERNAL_STORAGE},
                1);
        text1= findViewById(R.id.TextView);
        countDownStart();

        // Checking if its working correctly
//        new Timer().schedule(new TimerTask() {
//
//            @Override
//            public void run() {
//                Intent intent = new Intent(CountDown.this, BlastActivity.class);
//                startActivity(intent);
//                finish();
//            }
//        }, 5000);

    }

    public void countDownStart() {
        MediaPlayer mediaPlayer = MediaPlayer.create(CountDown.this,R.raw.back);
        mediaPlayer.start();
        handler = new Handler();
        runnable = new Runnable() {
            @Override
            public void run() {
                handler.postDelayed(this, 1000);

                // using try and catch for error handling
                try {
                    SimpleDateFormat dateFormat = new SimpleDateFormat(
                            "yyyy-MM-dd");

                    // Please here set your event date//YYYY-MM-DD
                    Date futureDate = dateFormat.parse("2021-04-13");

                    Date currentDate = new Date();
                    if (!currentDate.after(futureDate)) {
                        long diff = futureDate.getTime()
                                - currentDate.getTime();
                        long days = diff / (24 * 60 * 60 * 1000);
                        diff -= days * (24 * 60 * 60 * 1000);
                        long hours = diff / (60 * 60 * 1000);
                        diff -= hours * (60 * 60 * 1000);
                        long minutes = diff / (60 * 1000);
                        diff -= minutes * (60 * 1000);
                        long seconds = (diff / 1000)+(minutes*60)+(hours*60*60)+(days*60*60*60);
                        if(seconds==11){
                            mediaPlayer.stop();
                            MediaPlayer mediaPlayer1 = MediaPlayer.create(CountDown.this,R.raw.countdown);
                            mediaPlayer1.start();
                        }
                        text1.setText("" + String.format(FORMAT, seconds));
                    } else {
                        Intent intent = new Intent(CountDown.this,BlastActivity.class);
                        intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TASK | Intent.FLAG_ACTIVITY_NEW_TASK);
                        startActivityForResult(intent,20);
                        handler.removeCallbacksAndMessages(null);
                        finish();
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }

        };
        handler.postDelayed(runnable, 1 * 1000);
    }
}

// finish() -> It will finish the previous activity
// finishAffinity() -> It will finish some certain activities

