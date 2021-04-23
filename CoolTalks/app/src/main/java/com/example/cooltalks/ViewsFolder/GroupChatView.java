package com.example.cooltalks.ViewsFolder;

import android.app.AlertDialog;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.bumptech.glide.Glide;

import com.example.cooltalks.databinding.GroupReceiveMessageBinding;
import com.example.cooltalks.databinding.GroupSentMessageBinding;
import com.github.pgreze.reactions.ReactionPopup;
import com.github.pgreze.reactions.ReactionsConfig;
import com.github.pgreze.reactions.ReactionsConfigBuilder;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;
import com.example.cooltalks.Objects.Message;
import com.example.cooltalks.Objects.User;
import com.example.cooltalks.R;
import com.example.cooltalks.databinding.DeleteDialogBinding;


import java.util.ArrayList;

public class GroupChatView extends RecyclerView.Adapter {

    Context context;
    ArrayList<Message> messages;

    final int SentMessage = 1;
    final int ReceivedMessage = 2;

    public GroupChatView(Context context, ArrayList<Message> messages) {
        this.context = context;
        this.messages = messages;
    }

    @NonNull
    @Override
    public RecyclerView.ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        if(viewType == SentMessage) {
            View view = LayoutInflater.from(context).inflate(R.layout.group_sent_message, parent, false);
            return new SentViewHolder(view);
        } else {
            View view = LayoutInflater.from(context).inflate(R.layout.group_receive_message, parent, false);
            return new ReceiverViewHolder(view);
        }
    }

    @Override
    public int getItemViewType(int position) {
        Message message = messages.get(position);
        if(FirebaseAuth.getInstance().getUid().equals(message.getFriendId())) {
            return SentMessage;
        } else {
            return ReceivedMessage;
        }
    }

    @Override
    public void onBindViewHolder(@NonNull RecyclerView.ViewHolder holder, int position) {
        Message message = messages.get(position);

        int reactions[] = new int[]{
                R.drawable.like,
                R.drawable.love,
                R.drawable.laugh,
                R.drawable.omg,
                R.drawable.lovely,
                R.drawable.happy
        };

        ReactionsConfig config = new ReactionsConfigBuilder(context)
                .withReactions(reactions)
                .build();

        ReactionPopup popup = new ReactionPopup(context, config, (pos) -> {
            if(holder.getClass() == SentViewHolder.class) {
                SentViewHolder viewHolder = (SentViewHolder)holder;
                viewHolder.binding.emoji.setImageResource(reactions[pos]);
                viewHolder.binding.emoji.setVisibility(View.VISIBLE);
            } else {
                ReceiverViewHolder viewHolder = (ReceiverViewHolder)holder;
                viewHolder.binding.emoji.setImageResource(reactions[pos]);
                viewHolder.binding.emoji.setVisibility(View.VISIBLE);


            }

            message.setEmoji(pos);

            FirebaseDatabase.getInstance().getReference()
                    .child("public")
                    .child(message.getMessageId()).setValue(message);



            return true; // true is closing popup, false is requesting a new selection
        });


        if(holder.getClass() == SentViewHolder.class) {
            SentViewHolder viewHolder = (SentViewHolder)holder;

            if(message.getMessage().equals("photo")) {
                viewHolder.binding.image.setVisibility(View.VISIBLE);
                viewHolder.binding.message.setVisibility(View.GONE);
                Glide.with(context)
                        .load(message.getImageURL())
                        .placeholder(R.drawable.chats)
                        .into(viewHolder.binding.image);
            }

            FirebaseDatabase.getInstance()
                    .getReference().child("users")
                    .child(message.getMessageId())
                    .addListenerForSingleValueEvent(new ValueEventListener() {
                        @Override
                        public void onDataChange(@NonNull DataSnapshot snapshot) {
                            if(snapshot.exists()) {
                                User user = snapshot.getValue(User.class);
                                viewHolder.binding.name.setText("@" + user.getUserName());
                            }
                        }

                        @Override
                        public void onCancelled(@NonNull DatabaseError error) {

                        }
                    });

            viewHolder.binding.message.setText(message.getMessage());

            if(message.getEmoji() >= 0) {
                viewHolder.binding.emoji.setImageResource(reactions[message.getEmoji()]);
                viewHolder.binding.emoji.setVisibility(View.VISIBLE);
            } else {
                viewHolder.binding.emoji.setVisibility(View.GONE);
            }

            viewHolder.binding.message.setOnTouchListener(new View.OnTouchListener() {
                @Override
                public boolean onTouch(View v, MotionEvent event) {
                    popup.onTouch(v, event);
                    return false;
                }
            });

            viewHolder.binding.image.setOnTouchListener(new View.OnTouchListener() {
                @Override
                public boolean onTouch(View v, MotionEvent event) {
                    popup.onTouch(v, event);
                    return false;
                }
            });

            viewHolder.itemView.setOnLongClickListener(new View.OnLongClickListener() {
                @Override
                public boolean onLongClick(View v) {
                    View view = LayoutInflater.from(context).inflate(R.layout.delete_dialog, null);
                    DeleteDialogBinding binding = DeleteDialogBinding.bind(view);
                    AlertDialog dialog = new AlertDialog.Builder(context)
                            .setTitle("Delete Message")
                            .setView(binding.getRoot())
                            .create();

                    binding.everyone.setOnClickListener(new View.OnClickListener() {
                        @Override
                        public void onClick(View v) {
                            message.setMessage("This message is removed.");
                            message.setEmoji(-1);
                            FirebaseDatabase.getInstance().getReference()
                                    .child("public")
                                    .child(message.getMessageId()).setValue(message);

                            dialog.dismiss();
                        }
                    });

                    binding.delete.setOnClickListener(new View.OnClickListener() {
                        @Override
                        public void onClick(View v) {
                            FirebaseDatabase.getInstance().getReference()
                                    .child("public")
                                    .child(message.getMessageId()).setValue(null);
                            dialog.dismiss();
                        }
                    });

                    binding.cancel.setOnClickListener(new View.OnClickListener() {
                        @Override
                        public void onClick(View v) {
                            dialog.dismiss();
                        }
                    });

                    dialog.show();

                    return false;
                }
            });
        } else {
            ReceiverViewHolder viewHolder = (ReceiverViewHolder)holder;
            if(message.getMessage().equals("photo")) {
                viewHolder.binding.image.setVisibility(View.VISIBLE);
                viewHolder.binding.message.setVisibility(View.GONE);
                Glide.with(context)
                        .load(message.getImageURL())
                        .placeholder(R.drawable.chats)
                        .into(viewHolder.binding.image);
            }
            FirebaseDatabase.getInstance()
                    .getReference().child("users")
                    .child(message.getFriendId())
                    .addListenerForSingleValueEvent(new ValueEventListener() {
                        @Override
                        public void onDataChange(@NonNull DataSnapshot snapshot) {
                            if(snapshot.exists()) {
                                User user = snapshot.getValue(User.class);
                                viewHolder.binding.name.setText("@" + user.getUserName());
                            }
                        }

                        @Override
                        public void onCancelled(@NonNull DatabaseError error) {

                        }
                    });
            viewHolder.binding.message.setText(message.getMessage());

            if(message.getEmoji() >= 0) {
                //message.setFeeling(reactions[message.getFeeling()]);
                viewHolder.binding.emoji.setImageResource(reactions[message.getEmoji()]);
                viewHolder.binding.emoji.setVisibility(View.VISIBLE);
            } else {
                viewHolder.binding.emoji.setVisibility(View.GONE);
            }

            viewHolder.binding.message.setOnTouchListener(new View.OnTouchListener() {
                @Override
                public boolean onTouch(View v, MotionEvent event) {
                    popup.onTouch(v, event);
                    return false;
                }
            });

            viewHolder.binding.image.setOnTouchListener(new View.OnTouchListener() {
                @Override
                public boolean onTouch(View v, MotionEvent event) {
                    popup.onTouch(v, event);
                    return false;
                }
            });

            viewHolder.itemView.setOnLongClickListener(new View.OnLongClickListener() {
                @Override
                public boolean onLongClick(View v) {
                    View view = LayoutInflater.from(context).inflate(R.layout.delete_dialog, null);
                    DeleteDialogBinding binding = DeleteDialogBinding.bind(view);
                    AlertDialog dialog = new AlertDialog.Builder(context)
                            .setTitle("Delete Message")
                            .setView(binding.getRoot())
                            .create();

                    binding.everyone.setOnClickListener(new View.OnClickListener() {
                        @Override
                        public void onClick(View v) {
                            message.setMessage("This message is removed.");
                            message.setEmoji(-1);
                            FirebaseDatabase.getInstance().getReference()
                                    .child("public")
                                    .child(message.getMessageId()).setValue(message);

                            dialog.dismiss();
                        }
                    });

                    binding.delete.setOnClickListener(new View.OnClickListener() {
                        @Override
                        public void onClick(View v) {
                            FirebaseDatabase.getInstance().getReference()
                                    .child("public")
                                    .child(message.getMessageId()).setValue(null);
                            dialog.dismiss();
                        }
                    });

                    binding.cancel.setOnClickListener(new View.OnClickListener() {
                        @Override
                        public void onClick(View v) {
                            dialog.dismiss();
                        }
                    });

                    dialog.show();

                    return false;
                }
            });
        }
    }

    @Override
    public int getItemCount() {
        return messages.size();
    }

    public class SentViewHolder extends RecyclerView.ViewHolder {

        GroupSentMessageBinding binding;
        public SentViewHolder(@NonNull View itemView) {
            super(itemView);
            binding = GroupSentMessageBinding.bind(itemView);
        }
    }

    public class ReceiverViewHolder extends RecyclerView.ViewHolder {

        GroupReceiveMessageBinding binding;

        public ReceiverViewHolder(@NonNull View itemView) {
            super(itemView);
            binding = GroupReceiveMessageBinding.bind(itemView);
        }
    }

}
