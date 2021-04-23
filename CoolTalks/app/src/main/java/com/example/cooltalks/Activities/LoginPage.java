package com.example.cooltalks.Activities;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

import com.example.cooltalks.Objects.User;
import com.example.cooltalks.R;
import com.example.cooltalks.databinding.ActivityLoginPageBinding;
import com.google.android.gms.auth.api.signin.GoogleSignIn;
import com.google.android.gms.auth.api.signin.GoogleSignInAccount;
import com.google.android.gms.auth.api.signin.GoogleSignInClient;
import com.google.android.gms.auth.api.signin.GoogleSignInOptions;
import com.google.android.gms.common.api.ApiException;
import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.AuthCredential;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.auth.GoogleAuthProvider;
import com.google.firebase.database.FirebaseDatabase;

// PHONE AUTHENTICATION PAGE
public class LoginPage extends AppCompatActivity {

    ActivityLoginPageBinding binding;               // Declaring binding to bind login page layout
    GoogleSignInClient googleSignInClient;
    FirebaseAuth auth;
    FirebaseDatabase database;
    FirebaseUser user;
    User usergen;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityLoginPageBinding.inflate(getLayoutInflater());                //inflate is a method to add view (.xml) to activity on runtime .
        setContentView(binding.getRoot());                                                   // getRoot() gives you the reference to the root view


        getSupportActionBar().hide();                    // TO hide above text showing Cooltalks in blue background

        binding.PhoneNumberBox.requestFocus();           // This is used to open request focus so that we can open keyboard on app open
        auth = FirebaseAuth.getInstance();

        // Google sign in option
        GoogleSignInOptions gso = new GoogleSignInOptions
                .Builder(GoogleSignInOptions.DEFAULT_SIGN_IN)
                .requestIdToken(getString(R.string.default_web_client_id))
                .requestEmail()
                .build();
        googleSignInClient = GoogleSignIn.getClient(this, gso);

        // setting click,listener over continue button
        binding.SubmitButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(LoginPage.this, ValidatingPage.class);           // Intent are used to go from one activity to another
                intent.putExtra("PhoneNumber", binding.PhoneNumberBox.getText().toString());          // Getting text
                intent.putExtra("gender", binding.choice.getCheckedRadioButtonId());
                startActivity(intent);
                finish();
            }
        });

        binding.emailBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(LoginPage.this, EmailLogin.class);
                startActivity(intent);
            }
        });

        binding.googleBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                signIn();
            }
        });
    }
    int RC_SIGN_IN = 20;
    private void signIn () {
        Intent signInIntent = googleSignInClient.getSignInIntent();
        startActivityForResult(signInIntent, RC_SIGN_IN);
    }

    @Override
    public void onActivityResult ( int requestCode, int resultCode, Intent data){
        super.onActivityResult(requestCode, resultCode, data);

        // Result returned from launching the Intent from GoogleSignInApi.getSignInIntent(...);
        if (requestCode == RC_SIGN_IN) {
            Task<GoogleSignInAccount> task = GoogleSignIn.getSignedInAccountFromIntent(data);
            try {
                // Google Sign In was successful, authenticate with Firebase
                GoogleSignInAccount account = task.getResult(ApiException.class);
                Log.d("Tag", "firebaseAuthWithGoogle:" + account.getId());
                firebaseAuthWithGoogle(account.getIdToken());
            } catch (ApiException e) {
                // Google Sign In failed, update UI appropriately
                Log.w("Tag", "Google sign in failed", e);
            }
        }
    }

    private void firebaseAuthWithGoogle(String idToken) {
        AuthCredential credential = GoogleAuthProvider.getCredential(idToken, null);
        auth.signInWithCredential(credential)
                .addOnCompleteListener(this, new OnCompleteListener<AuthResult>() {
                    @Override
                    public void onComplete(@NonNull Task<AuthResult> task) {
                        if (task.isSuccessful()) {
                            // Sign in success, update UI with the signed-in user's information
                            Log.d("Tag", "signInWithCredential:success");
                            user = auth.getCurrentUser();
                            User user1 = new User();
                            user1.setUserId(user.getUid());
                            user1.setUserName(user.getDisplayName());
                            user1.setUserProfileImage(user.getPhotoUrl().toString());
                            database.getReference().child("users").child(user.getUid()).setValue(user1);
                            Intent intent = new Intent(LoginPage.this,MainActivity.class);
                            startActivity(intent);
                            finish();
                            Toast.makeText(LoginPage.this, "SignIn with Google successful !", Toast.LENGTH_SHORT).show();
//                            updateUI(user);
                        } else {
                            // If sign in fails, display a message to the user.
                            Log.w("Tag", "signInWithCredential:failure", task.getException());
//                            updateUI(null);
                        }
                    }
                });
    }
}