package com.example.birthday;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;


public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        getSupportActionBar().hide();
        finishActivity(30);


        // Starting background music
        MediaPlayer mediaPlayer = MediaPlayer.create(MainActivity.this,R.raw.background);
        mediaPlayer.start();

        // First button click listener to move to another activity
        final Button button = findViewById(R.id.gettoknowbutton);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this,GetToKnow.class);
                mediaPlayer.stop();
                startActivity(intent);

            }
        });
        final Button button1 = findViewById(R.id.suggestionbutton);
        button1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this,SuggestionPage.class);
                mediaPlayer.stop();
                startActivity(intent);

            }
        });
        final Button button2 = findViewById(R.id.secure);
        button2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this,secret.class);
                mediaPlayer.stop();
                startActivity(intent);

            }
        });

        final Button button3 = findViewById(R.id.anonymous);
        button3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(MainActivity.this, "Please give some message....", Toast.LENGTH_SHORT).show();
                Intent intent = new Intent(MainActivity.this,anonymous.class);
                mediaPlayer.stop();
                startActivity(intent);
            }
        });
    }

}