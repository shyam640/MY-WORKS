package com.example.birthday;

import android.annotation.SuppressLint;
import android.content.Context;
import android.graphics.Typeface;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.Window;
import android.widget.ImageView;
import android.widget.LinearLayout.LayoutParams;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.content.ContextCompat;

import java.util.ArrayList;
import java.util.Collections;

public class GetToKnow extends AppCompatActivity {
    int windowwidth;
    int screenCenter;
    int x_cord, y_cord, x, y;
    int Likes = 0;
    int i;
    public RelativeLayout parentView;
    float alphaValue = 0;
    private Context context;
    ArrayList<UserDataModel> userDataModelArrayList;
    @SuppressLint("ClickableViewAccessibility")

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        setContentView(R.layout.gettoknow);

        context =  GetToKnow.this;

        parentView = (RelativeLayout) findViewById(R.id.main_layoutview);

        // Getting device dimensions
        DisplayMetrics displayMetrics = new DisplayMetrics();
        getWindowManager().getDefaultDisplay().getMetrics(displayMetrics);

        windowwidth = displayMetrics.widthPixels;
        screenCenter = windowwidth / 2;

        userDataModelArrayList = new ArrayList<>();
        getArrayData();
        for (i = 0; i < userDataModelArrayList.size(); i++) {
            LayoutInflater inflate =
                    (LayoutInflater) GetToKnow.this.getSystemService(Context.LAYOUT_INFLATER_SERVICE);

            // putting layout over this page container
            final View containerView = inflate.inflate(R.layout.swipeactivitylayout, null);

            ImageView userIMG = containerView.findViewById(R.id.userIMG);
            RelativeLayout relativeLayoutContainer = containerView.findViewById(R.id.relative_container);


            LayoutParams layoutParams = new LayoutParams(
                    LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT);

            containerView.setLayoutParams(layoutParams);

            containerView.setTag(i);
            userIMG.setBackgroundResource(userDataModelArrayList.get(i).getPhoto());

            LayoutParams layoutTvParams = new LayoutParams(
                    LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT);


            // ADD dynamically True TextView on image.
            final TextView tvLike = new TextView(context);
            tvLike.setLayoutParams(layoutTvParams);
            tvLike.setPadding(10, 10, 10, 10);
            tvLike.setText("True");
            tvLike.setGravity(Gravity.CENTER);
            tvLike.setTypeface(Typeface.defaultFromStyle(Typeface.BOLD));
            tvLike.setTextSize(25);
            tvLike.setTextColor(ContextCompat.getColor(context, R.color.colorRed));
            tvLike.setX(20);
            tvLike.setY(100);
            tvLike.setRotation(-50);
            tvLike.setAlpha(alphaValue);
            relativeLayoutContainer.addView(tvLike);


//            ADD dynamically False TextView on image.
            final TextView tvUnLike = new TextView(context);
            tvUnLike.setLayoutParams(layoutTvParams);
            tvUnLike.setPadding(10, 10, 10, 10);
            tvUnLike.setText("False");
            tvUnLike.setGravity(Gravity.CENTER);
            tvUnLike.setTypeface(Typeface.defaultFromStyle(Typeface.BOLD));
            tvUnLike.setTextSize(25);
            tvUnLike.setTextColor(ContextCompat.getColor(context, R.color.colorRed));
            tvUnLike.setX(500);
            tvUnLike.setY(150);
            tvUnLike.setRotation(50);
            tvUnLike.setAlpha(alphaValue);
            relativeLayoutContainer.addView(tvUnLike);


            TextView tvName = containerView.findViewById(R.id.tvName);
            TextView tvTotLikes = containerView.findViewById(R.id.tvTotalLikes);

            tvName.setText(userDataModelArrayList.get(i).getName());
            tvTotLikes.setText(userDataModelArrayList.get(i).getTotalLikes());

            // setting touch listener for swipe activity
            relativeLayoutContainer.setOnTouchListener(new View.OnTouchListener() {

                @Override
                public boolean onTouch(View v, MotionEvent event) {

                    // Getting position
                    x_cord = (int) event.getRawX();
                    y_cord = (int) event.getRawY();

                    containerView.setX(0);
                    containerView.setY(0);

                    switch (event.getAction()) {
                        case MotionEvent.ACTION_DOWN:                                       // If it is swipped to down then nothing happens

                            x = (int) event.getX();
                            y = (int) event.getY();


                            Log.v("On touch", x + " " + y);
                            break;
                        case MotionEvent.ACTION_MOVE:                                       // If swipped somewhere then checking where it is moved

                            x_cord = (int) event.getRawX();
                            // smoother animation.
                            y_cord = (int) event.getRawY();

                            containerView.setX(x_cord - x);
                            containerView.setY(y_cord - y);

                            // Checking if activity is swipped right then checking if it crosses right screen the show True on picture then
                            if (x_cord >= screenCenter) {
                                containerView.setRotation((float) ((x_cord - screenCenter) * (Math.PI / 32)));
                                if (x_cord > (screenCenter + (screenCenter / 2))) {
                                    tvLike.setAlpha(1);
                                    if (x_cord > (windowwidth - (screenCenter / 4))) {
                                        Likes = 2;
                                    } else {
                                        Likes = 0;
                                    }
                                } else {
                                    Likes = 0;
                                    tvLike.setAlpha(0);
                                }
                                tvUnLike.setAlpha(0);
                            } else {
                                // rotate image while moving
                                containerView.setRotation((float) ((x_cord - screenCenter) * (Math.PI / 32)));
                                if (x_cord < (screenCenter / 2)) {
                                    tvUnLike.setAlpha(1);
                                    if (x_cord < screenCenter / 4) {
                                        Likes = 1;
                                    } else {
                                        Likes = 0;
                                    }
                                } else {
                                    Likes = 0;
                                    tvUnLike.setAlpha(0);
                                }
                                tvLike.setAlpha(0);
                            }

                            break;
                        case MotionEvent.ACTION_UP:                                                     // if activity is moved up then somethings happens

                            x_cord = (int) event.getRawX();
                            y_cord = (int) event.getRawY();

                            Log.e("X Point", "" + x_cord + " , Y " + y_cord);
                            tvUnLike.setAlpha(0);
                            tvLike.setAlpha(0);

                            if (Likes == 0) {
                                Toast.makeText(context, "False", Toast.LENGTH_SHORT).show();
                                Log.e("Event_Status :-> ", "False");
                                containerView.setX(0);
                                containerView.setY(0);
                                containerView.setRotation(0);
                            } else if (Likes == 1) {
                                Toast.makeText(context, "False", Toast.LENGTH_SHORT).show();
                                Log.e("Event_Status :-> ", "False");
                                parentView.removeView(containerView);
                            } else if (Likes == 2) {
                                Toast.makeText(context, "True", Toast.LENGTH_SHORT).show();
                                Log.e("Event_Status :-> ", "True");
                                parentView.removeView(containerView);
                            }
                            break;
                        default:
                            break;
                    }
                    return true;
                }
            });

            parentView.addView(containerView);

        }
    }

    // Adding pictures
        private void getArrayData() {

            UserDataModel model = new UserDataModel();
            model.setName("Favourite Food");
            model.setTotalLikes("65%");
            model.setPhoto(R.drawable.cholebhature);
            userDataModelArrayList.add(model);


            UserDataModel model2 = new UserDataModel();
            model2.setName("Favourite Place");
            model2.setTotalLikes("75%");
            model2.setPhoto(R.drawable.maldives);
            userDataModelArrayList.add(model2);

            UserDataModel model3 = new UserDataModel();
            model3.setName("Tea / Coffee");
            model3.setTotalLikes("90%");
            model3.setPhoto(R.drawable.coffee);
            userDataModelArrayList.add(model3);


            UserDataModel model4 = new UserDataModel();
            model4.setName("Favourite Color");
            model4.setTotalLikes("35%");
            model4.setPhoto(R.drawable.redcolor);
            userDataModelArrayList.add(model4);


            UserDataModel model5 = new UserDataModel();
            model5.setName("Favourite Show");
            model5.setTotalLikes("50%");
            model5.setPhoto(R.drawable.kdrama);
            userDataModelArrayList.add(model5);

            UserDataModel model6 = new UserDataModel();
            model6.setName("Favourite item");
            model6.setTotalLikes("60%");
            model6.setPhoto(R.drawable.earings);
            userDataModelArrayList.add(model6);


            UserDataModel model7 = new UserDataModel();
            model7.setName("Favourite Social Media");
            model7.setTotalLikes("90%");
            model7.setPhoto(R.drawable.twitter);
            userDataModelArrayList.add(model7);


            UserDataModel model8 = new UserDataModel();
            model8.setName("Favourite Fruit");
            model8.setTotalLikes("70%");
            model8.setPhoto(R.drawable.mango);
            userDataModelArrayList.add(model8);

            UserDataModel model9 = new UserDataModel();
            model9.setName("That you Don't Like");
            model9.setTotalLikes("20%");
            model9.setPhoto(R.drawable.talking);
            userDataModelArrayList.add(model9);

            UserDataModel mode10 = new UserDataModel();
            mode10.setName("That you Love");
            mode10.setTotalLikes("80%");
            mode10.setPhoto(R.drawable.book);
            userDataModelArrayList.add(mode10);

            UserDataModel mode11 = new UserDataModel();
            mode11.setName("Favourite Dessert");
            mode11.setTotalLikes("80%");
            mode11.setPhoto(R.drawable.icecream);
            userDataModelArrayList.add(mode11);

            UserDataModel mode12 = new UserDataModel();
            mode12.setName("Do in Free Time");
            mode12.setTotalLikes("80%");
            mode12.setPhoto(R.drawable.painting);
            userDataModelArrayList.add(mode12);

            UserDataModel mode13 = new UserDataModel();
            mode13.setName("Spicy thing that u like");
            mode13.setTotalLikes("80%");
            mode13.setPhoto(R.drawable.momos);
            userDataModelArrayList.add(mode13);

            UserDataModel mode14 = new UserDataModel();
            mode14.setName("Favourite Toy");
            mode14.setTotalLikes("80%");
            mode14.setPhoto(R.drawable.teddy);
            userDataModelArrayList.add(mode14);

            Collections.reverse(userDataModelArrayList);

        }
}
