package com.example.cooltalks.Activities;

import android.app.ProgressDialog;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import com.example.cooltalks.Objects.User;
import com.example.cooltalks.databinding.ActivityEmailLoginBinding;
import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.database.FirebaseDatabase;

public class EmailLogin extends AppCompatActivity {
    FirebaseAuth auth;
    FirebaseDatabase database;

    ActivityEmailLoginBinding binding;
    ProgressDialog dialog;
    ProgressDialog dialog1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityEmailLoginBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
        getSupportActionBar().hide();

        // signup dialog
        dialog = new ProgressDialog(EmailLogin.this);
        dialog.setTitle("CoolTalks Says..");
        dialog.setMessage("Creating Account...");
        dialog.setCancelable(false);

        //signin dialog
        dialog1 = new ProgressDialog(EmailLogin.this);
        dialog1.setTitle("CoolTalks Says..");
        dialog1.setMessage("Logging in...");
        dialog1.setCancelable(false);

        auth = FirebaseAuth.getInstance();
        database = FirebaseDatabase.getInstance();

        String gender = binding.choice.toString();
        Toast.makeText(getApplicationContext(), gender, Toast.LENGTH_SHORT).show();
        binding.SubmitButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(binding.EmailBox.getText().toString().isEmpty()){
                    binding.EmailBox.setError("Please Provide email address !");
                    binding.EmailBox.requestFocus();
                }
                if(binding.password.getText().toString().isEmpty()){
                    binding.password.setError("Please Enter a valid Password !");
                }
                auth.signInWithEmailAndPassword(binding.EmailBox.getText().toString(),binding.password.getText().toString()).addOnCompleteListener(new OnCompleteListener<AuthResult>() {
                    @Override
                    public void onComplete(@NonNull Task<AuthResult> task) {
                        dialog1.show();
                        if(task.isSuccessful()){
                            dialog1.dismiss();
                            Intent intent = new Intent(EmailLogin.this,MainActivity.class);
                            startActivity(intent);
                            finish();
                        }else{
                            dialog1.dismiss();
                            Toast.makeText(EmailLogin.this, "Creating User !", Toast.LENGTH_SHORT).show();
                            dialog.show();
                            auth.createUserWithEmailAndPassword(binding.EmailBox.getText().toString(),binding.password.getText().toString()).addOnCompleteListener(new OnCompleteListener<AuthResult>() {
                                @Override
                                public void onComplete(@NonNull Task<AuthResult> task) {
                                    binding.msgtext.setVisibility(View.VISIBLE);
                                    binding.cardView.setVisibility(View.GONE);
                                    if(task.isSuccessful()){
                                        dialog.dismiss();
                                        User user = new User(binding.EmailBox.getText().toString(),binding.password.getText().toString(),"Not Provided");
                                        String id = task.getResult().getUser().getUid();
                                        database.getReference().child("users").child(id).setValue(user);
                                        Intent intent = new Intent(EmailLogin.this,ProfilePage.class);
                                        startActivity(intent);
                                        finish();
                                    }else{
                                        Toast.makeText(EmailLogin.this, "User already Exists ! Please Login", Toast.LENGTH_SHORT).show();
                                    }
                                }
                            });
                        }
                    }
                });

            }
        });

        if(auth.getCurrentUser()!=null){
            Intent intent = new Intent(EmailLogin.this,MainActivity.class);
            startActivity(intent);
            finish();
        }
    }
}