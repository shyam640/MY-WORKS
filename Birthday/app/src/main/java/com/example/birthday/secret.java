package com.example.birthday;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

public class secret extends AppCompatActivity {
    EditText username,secretkey;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.secret);

        username = (EditText)findViewById(R.id.username);
        secretkey = (EditText)findViewById(R.id.securitykey);

        Button button = findViewById(R.id.submit);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(secretkey.getText().toString().equals("9422176364")){
                    Intent intent = new Intent(secret.this,confessPage.class);
                    startActivity(intent);
                    Toast.makeText(secret.this,"You guessed the correct key !", Toast.LENGTH_SHORT).show();
                }else{
                    Intent intent = new Intent(secret.this,MainActivity.class);
                    startActivity(intent);
                    Toast.makeText(secret.this, "come back when you find security Key !", Toast.LENGTH_SHORT).show();
                }
            }
        });

    }
}
