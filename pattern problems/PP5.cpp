/*Printing hollow inverted triangle*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main(){
   system("CLS");
   int n;
   cin>>n;
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
      if(i==1||j==1){
         cout<<"*";
      }
      else if(j==n-i+1){
         cout<<"*";
      }
         else {
         cout<<" ";
      }
      }
      cout<<endl;
   }
   return 0;
}