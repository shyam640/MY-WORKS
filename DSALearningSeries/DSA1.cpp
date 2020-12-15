/* Program to see the funtioning of all stack DS funtion
    push() , pop() , isEmpty() , isfull() , count() , peek() , change() , display() */

#include<iostream>
#include<stdlib.h>
#include<string>
#include<bits/stdc++.h>

using namespace std;

 class Stack{
    private:
    int top;
    int skt[5];
    public:
    Stack(){
      top=-1;
       for(int i=0;i<5;i++){
          skt[i]=0;
       }
       cout<<"Available values in stack : "<<endl;
       for(int i=0;i<5;i++){
          cout<<skt[i]<<" ";
       }cout<<endl<<endl;

      }

    bool isEmpty(){
      if(top == -1){
         return true;
      }else{
         return false;
      }
   } 

    bool isFull(){
      if(top == 4){
         return true;
      }else{
         return false;
      }
   }

   void push(int value){
      if(isFull()==true) {
       cout<<"Stack Overflow !!!"<<endl;
      }else{
         top++;
         skt[top] = value;
      }
   }

   int pop(){
      if(isEmpty()){
         cout<<"Stack Underflow !!!"<<endl;
         return 0;
      }else{
         int pop_value = skt[top];
         skt[top]=0;
         top--;
         cout<<"Popped value is : ";
         return pop_value;
      }
   }

   int count(){
     return (top+1);
   }

   int peek(int pos){
     if(isEmpty()){
        cout<<"Stack Overflow !!!"<<endl;
        return 0;
     }else{
        cout<<"Element at the position "<<pos<<"is : ";
        return skt[pos];
     }
   }

   void change(int index , int new_val){
      if(isEmpty()){
         cout<<"Stack Overflow !!!"<<endl;
      }else{
         skt[index] = new_val;
         cout<<"Value change at index "<<index;
      }
   }

   void display(){
      cout<<"All the values in the stack are :-"<<endl;
      for(int i=4;i>=0;i--){
         cout<<skt[i]<<endl;
      }
      cout<<endl;
   }
   
   };

 int main(){
    system("CLS");
    
       Stack s1;
       int n;
      
       int opt;int num1;int num2;
       int position , val;
       do{

       cout<<"Enter choices between 1-10 :"<<endl<<endl;
       cout<<"Press 1 to push()"<<endl;
       cout<<"Press 2 to pop()"<<endl;
       cout<<"Press 3 to isEmpty()"<<endl;
       cout<<"Press 4 to isFull()"<<endl;
       cout<<"Press 5 to count()"<<endl;
       cout<<"Press 6 to peak()"<<endl;
       cout<<"Press 7 to change()"<<endl;
       cout<<"Press 8 to display()"<<endl;
       cout<<"Press 9 to Clear Screen..."<<endl;
       cout<<"Press 0 to Exit..."<<endl<<endl;

          cin>>opt;
         switch (opt)
         {
     
             case 1:
                   cout<<"Enter a number to be pushed : ";
                   cin>>num1;
                   s1.push(num1); 
                   break;
             case 2:
                   s1.pop();
                   break;
             case 3:
                   if(s1.isEmpty()){
                     cout<<"Stack is Empty"<<endl;
                   }else{
                      cout<<"Stack is not Empty"<<endl;
                   }
                   break;
             case 4:
                   if(s1.isFull()){
                      cout<<"Stack is full"<<endl;
                   }else{
                      cout<<"Stack is not full"<<endl;
                   }
                   break;
             case 5:
                   cout<<"Total Elements present now in stack is/are "<<s1.count()<<endl;
                   break;
             case 6:
                   cout<<"Enter position or index :";
                   cin>>num2;
                   s1.peek(num2);
                   break;
             case 7: 
                   cout<<"Enter the position and value which need to be changed:";
                   cin>>position>>val;
                   s1.change(position , val);
                   break;
             case 8:
                   s1.display();
                   break;
             case 9:
                   system("CLS");
                   break;
             case 0:
                   break;      
             default:
                   cout<<"Enter a valid no. between 1-10 only....."<<endl;
                   break;
          }

      }while(opt != 0);
     
    return 0;
   } 
     

     