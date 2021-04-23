package com.example.cooltalks.Activities;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;

import com.example.cooltalks.databinding.ActivityStartAnimationBinding;
import com.google.firebase.auth.FirebaseAuth;

import java.util.Timer;

public class StartAnimation extends AppCompatActivity {
    ActivityStartAnimationBinding binding;
    FirebaseAuth auth;              // Firebase authorisation declaration
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityStartAnimationBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
        Handler handler = new Handler();
        handler.postDelayed(new Runnable() {
            @Override
            public void run() {
                // Checking if we are already signed in
                auth = FirebaseAuth.getInstance();
                if(auth.getCurrentUser()!=null){
                    Intent intent = new Intent(StartAnimation.this,MainActivity.class);
                    startActivity(intent);
                    finish();
                }else{
                    Intent intent = new Intent(StartAnimation.this,LoginPage.class);
                    startActivity(intent);
                    finish();
                }
            }
        },6000);



    }
}