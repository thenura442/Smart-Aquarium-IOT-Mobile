package com.example.smartaquarium;

import static java.security.AccessController.getContext;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.ktx.Firebase;

public class ControlPanel extends AppCompatActivity {


    private Button editProfile;
    private DatabaseReference mRootRef;
    private FirebaseUser fUser;
    private FirebaseAuth Firebase;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_control_panel);

        String profilerid = "";
        fUser = FirebaseAuth.getInstance().getCurrentUser();

        editProfile.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String temperature = mRootRef.toString();
                String waterlevel = mRootRef.toString();

                String ldr = mRootRef.toString();

                String lightset;

                FirebaseDatabase.getInstance().getReference().child("Follow").child(fUser.getUid())
                        .child("following").child(temperature).setValue(true);

                FirebaseDatabase.getInstance().getReference().child("Follow").child(profilerid)
                        .child("followers").child(fUser.getUid()).setValue(true);

                FirebaseDatabase.getInstance().getReference().child("Follow").child(fUser.getUid())
                        .child("following").child(temperature).setValue(true);

                FirebaseDatabase.getInstance().getReference().child("Follow").child(profilerid)
                        .child("followers").child(fUser.getUid()).setValue(true);


                    }
        });
    }
}