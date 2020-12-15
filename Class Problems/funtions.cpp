#include<iostream>
#include<stdlib.h>

#include<bits/stdc++.h>
using namespace std;

void evenodd(int n){
   if(n%2==0)
   cout<<"Number is Even"<<endl;
   else
   cout<<"Number is Odd"<<endl;
}

void checkalpha(char c){
   if(c>'A' || c<'Z' || c>'a' || c<'z')
      cout<<"Character is Alphabet!"<<endl;
   else
      cout<<"Character is not a Alphabet"<<endl;   
}

void max_min(int a,int b, int c){
   int x=max(a,b);
   int actual_max=max(x,c);
   int n=min(a,b);
   int actual_min=min(n,c);
   cout<<"Maximum :"<<actual_max<<endl;
   cout<<"Minimum :"<<actual_min<<endl;
}

void Swap(int t1 , int t2){
   int temp=t1;
   t1=t2;
   t2=temp;
   cout<<"After Swaping"<<endl;
   cout<<t1<<" "<<t2<<endl;
}

void canVote(int v1){
   if(v1>=18)
   cout<<"Person can vote"<<endl;
   else
   cout<<"Person can't vote"<<endl;   
}

int main(){
   system("CLS");

   int num1;
   cout<<"Enter number to be checked if it is even or odd :";
   cin>>num1;
   evenodd(num1);
   cout<<endl;

   char ch;
   cout<<"Enter character to be checked for albhabet or not :";
   cin>>ch;
   checkalpha(ch);
   cout<<endl;

   int n1,n2,n3;
   cout<<"Enter three integers to find maximum and minimum of them :";
   cin>>n1>>n2>>n3;
   max_min(n1,n2,n3);
   cout<<endl;

   int val1 , val2;
   cout<<"Enter two numbers to be swaped :";
   cin>>val1>>val2;
   cout<<"Before Swaping"<<endl;
   cout<<val1<<" "<<val2<<endl;
   Swap(val1,val2);
   cout<<endl;

   int age;
   cout<<"Enter age for checking eligibility:";
   cin>>age;
   canVote(age);
   cout<<endl;

   return 0;
   }