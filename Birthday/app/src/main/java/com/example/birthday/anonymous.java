package com.example.birthday;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;

public class anonymous extends AppCompatActivity {
    FirebaseDatabase database;
    DatabaseReference reference;
    EditText userMsg;
    Button sendBtn;
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.anonymous);
        userMsg = (EditText)findViewById(R.id.userEnteredMsg);
        sendBtn = (Button)findViewById(R.id.sent);
        sendBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String msg = userMsg.getText().toString();
                if(msg.length()>0){
                    database = FirebaseDatabase.getInstance();
                    reference = database.getReference("username");
                    AnonymousDataHandler anonymousDataHandler1 = new AnonymousDataHandler();
                    String msgofUser = msg;
                    AnonymousDataHandler anonymousDataHandler = new AnonymousDataHandler(msgofUser);
                    reference.child("userMessage").setValue(msgofUser);
                    Toast.makeText(anonymous.this, "Thanks for sharing your feelings ! You can go back Now ...", Toast.LENGTH_SHORT).show();
                }else{
                    Toast.makeText(anonymous.this, "Please Enter Message ,Please !!", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }
}
