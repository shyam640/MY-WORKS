package com.example.cooltalks;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.RadioButton;
import android.widget.RadioGroup;

import com.example.cooltalks.databinding.ActivityLoginPageBinding;
import com.google.firebase.auth.FirebaseAuth;

public class LoginPage extends AppCompatActivity {
    ActivityLoginPageBinding binding;               // Declaring binding
    FirebaseAuth auth;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityLoginPageBinding.inflate(getLayoutInflater());        //inflate is a method to add view (.xml) to activity on runtime .
        setContentView(binding.getRoot());                                  // getRoot() gives you the reference to the root view

        // Checking if we are already signed in
        auth = FirebaseAuth.getInstance();
        if(auth.getCurrentUser() != null){
            Intent intent = new Intent(LoginPage.this,MainActivity.class);
            intent.putExtra("Gender",binding.gender.getCheckedRadioButtonId());
            startActivity(intent);
            finish();
        }

        getSupportActionBar().hide();                    // TO hide above text showing Cooltalks in blue background

        binding.PhoneNumberBox.requestFocus();           // This is used to open request focus so that we can open keyboard on app open

        // setting click,listener over continue button
        binding.SubmitButton.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick (View v){
                Intent intent = new Intent(LoginPage.this,ValidatingPage.class);           // Intent are used to go from one activity to another
                intent.putExtra("PhoneNumber",binding.PhoneNumberBox.getText().toString());          // Getting text
                intent.putExtra("Gender",binding.gender.getCheckedRadioButtonId());
                startActivity(intent);
            }
        });
    }
}