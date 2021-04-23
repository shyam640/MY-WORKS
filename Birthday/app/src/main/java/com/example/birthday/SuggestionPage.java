package com.example.birthday;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;

import org.apache.http.params.HttpParams;

public class SuggestionPage extends AppCompatActivity {
    EditText name;
    EditText msgText;
    Button sendBtn;

    // Adding firebase database to get message
    FirebaseDatabase database;
    DatabaseReference reference;                // getting database reference
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.suggestion);
        name = (EditText) findViewById(R.id.nameTextField);
        msgText = (EditText) findViewById(R.id.msgTextField);
        sendBtn = (Button) findViewById(R.id.sendButton);
    }
    public void send(View v){
        String msg = msgText.getText().toString();
        if(msg.length()>0){
            database = FirebaseDatabase.getInstance();
            // creating node "username" and adding "name" and "message" in child node of it .
            reference = database.getReference("username");
            userDataHandler handler = new userDataHandler();
            String userName = name.getText().toString();
            String userMessage = msgText.getText().toString();
            userDataHandler handler1 = new userDataHandler(userName,userMessage);
            reference.child(userName).setValue(handler1);
            Intent intent = new Intent(SuggestionPage.this,MainActivity.class);
            startActivity(intent);
            finish();
            Toast.makeText(this, "Your Suggestion Submitted successfully !", Toast.LENGTH_SHORT).show();
        }else{
            Toast.makeText(this, "Please Provide Suggestion !", Toast.LENGTH_SHORT).show();
        }
    }
}
