/*printing hollow rectangle*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main()
{
   system("CLS");
   int row,col;
   printf("Enter the Number : \n");
   scanf("%d %d \n", &row , &col);
   for(int i=1;i<=row;i++){
   for(int j=1;j<=col;j++){
      if(i==1||i==row||j==1||j==col){
         cout<<"*";
      }
      else 
      cout<<" ";
     }
   cout<<endl;
   }
   return 0;
}