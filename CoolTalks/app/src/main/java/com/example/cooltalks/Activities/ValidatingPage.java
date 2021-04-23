package com.example.cooltalks.Activities;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.app.ProgressDialog;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.inputmethod.InputMethodManager;
import android.widget.Toast;

import com.example.cooltalks.databinding.ActivityValidatingPageBinding;
import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.FirebaseException;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseAuthSettings;
import com.google.firebase.auth.PhoneAuthCredential;
import com.google.firebase.auth.PhoneAuthOptions;
import com.google.firebase.auth.PhoneAuthProvider;
import in.aabhasjindal.otptextview.OTPListener;

import java.util.concurrent.TimeUnit;

public class ValidatingPage extends AppCompatActivity {
    ActivityValidatingPageBinding binding;              // Declaring binding
    FirebaseAuth auth;                                  // Firebase authentication variable
    String verificationId;                                  // Creating variable to store verify id i.e. otp
    ProgressDialog dialog;                              // Dialog showing loading page

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityValidatingPageBinding.inflate(getLayoutInflater());               // inflate is method to add view (.xml) to activity on runtime
        setContentView(binding.getRoot());                                                  // Getting reference to root view

        // Adding a loader after entering phone number
        dialog = new ProgressDialog(this);              // This will create a new dialog
        dialog.setMessage("Sending OTP...");                        // This is the message shown
        dialog.setCancelable(false);                            // This ensures that process can't be cancelled
        dialog.show();                                       // Showing dialog box

        getSupportActionBar().hide();                           // TO hide above text showing Cooltalks in blue background

        auth = FirebaseAuth.getInstance();
        String PhoneNumber = getIntent().getStringExtra("PhoneNumber");     // variable PhoneNumber stores value entered in phone number box
                // value in phoneNumber comes through intent and we need string in phoneNumberBox so used .getStringExtra()
        String Gender = getIntent().getStringExtra("gender");
        String smsCode = binding.otpView.getOTP();

        binding.textView1.setText("Enter the OTP sent on phone number "+PhoneNumber);
        // Checking for otp verification through Phone Number
        FirebaseAuth.getInstance().getFirebaseAuthSettings()
                .setAppVerificationDisabledForTesting(true);
        FirebaseAuthSettings firebaseAuthSettings = auth.getFirebaseAuthSettings();
        firebaseAuthSettings.setAutoRetrievedSmsCodeForPhoneNumber(PhoneNumber,smsCode);
        PhoneAuthOptions options = PhoneAuthOptions.newBuilder(auth)
                .setPhoneNumber(PhoneNumber)
                .setTimeout(1L, TimeUnit.MINUTES)
                .setActivity(this)
                .setCallbacks(new PhoneAuthProvider.OnVerificationStateChangedCallbacks() {
                    @Override
                    public void onVerificationCompleted(@NonNull PhoneAuthCredential phoneAuthCredential) {
                        Toast.makeText(ValidatingPage.this, "Verification SuccessFul !", Toast.LENGTH_SHORT).show();
                    }

                    @Override
                    public void onVerificationFailed(@NonNull FirebaseException e) {
                        Toast.makeText(ValidatingPage.this, "Verification Failed !", Toast.LENGTH_SHORT).show();
                    }

                    @Override
                    public void onCodeSent(@NonNull String verifyId, @NonNull PhoneAuthProvider.ForceResendingToken forceResendingToken) {
                        super.onCodeSent(verifyId, forceResendingToken);

                        dialog.dismiss();                           // This tells as our code is sent cancel loader
                        verificationId = verifyId;
                        PhoneAuthProvider.ForceResendingToken resendOTP = forceResendingToken;
                        firebaseAuthSettings.forceRecaptchaFlowForTesting(true);

                        // Opening keyboard on otp activity forcefully
                        InputMethodManager imm = (InputMethodManager) getSystemService(Context.INPUT_METHOD_SERVICE);
                        imm.toggleSoftInput(InputMethodManager.SHOW_FORCED,0);
                        binding.otpView.requestFocus();
                    }
                }).build();
        PhoneAuthProvider.verifyPhoneNumber(options);             // This line will send code to phone

        // Below methods are defined in aabhasjindal implementation method
        binding.otpView.setOtpListener(new OTPListener() {
            @Override
            public void onInteractionListener() {

            }

            @Override
            public void onOTPComplete(String otp) {
                PhoneAuthCredential credential = PhoneAuthProvider.getCredential(verificationId, otp);                       // Checking Credentials
                auth.signInWithCredential(credential).addOnCompleteListener(new OnCompleteListener<AuthResult>() {
                    @Override
                    public void onComplete(@NonNull Task<AuthResult> task) {
                        if (task.isSuccessful()) {
                            FirebaseAuth.getInstance().getFirebaseAuthSettings().forceRecaptchaFlowForTesting(true);
                            Toast.makeText(ValidatingPage.this, "Login Successful !", Toast.LENGTH_SHORT).show();
                            Intent intent = new Intent(ValidatingPage.this,ProfilePage.class);
                            intent.putExtra("gender",Gender);
                            startActivity(intent);
                            finishAffinity();
                        }else {
                            Toast.makeText(ValidatingPage.this, "Login Failed !", Toast.LENGTH_SHORT).show();
                        }
                    }
                });
            }
        });
    }
}