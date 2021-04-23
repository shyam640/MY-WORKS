package com.example.unitconverter;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private Button button;
    private TextView answer;
    private EditText fillvalue;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        fillvalue = findViewById(R.id.fillvalue);
        button = findViewById(R.id.button);
        answer = findViewById(R.id.answer);
        // METHOD 1
//        button.setOnClickListener(new View.OnClickListener(){
//            @Override
//            public void onClick(View view) {
////                Toast.makeText( context:MainActivity.this, "Value in Pound is Calculated",Toast.LENGTH_SHORT).show();
//                String s = fillvalue.getText().toString();
//                int kg = Integer.parseInt(s);
//                double pound = 2.205*kg;
//                answer.setText("The Corresponding value in pounds  is " + pound);
//            }
//        });
        // METHOD 2
        public void Calculate(View view){
            String s = fillvalue.getText().toString();
            int kg = Integer.parseInt(s);
            double pound = 2.205*kg;
            answer.setText("The Corresponding value in pounds  is " + pound);
        }
    }
}