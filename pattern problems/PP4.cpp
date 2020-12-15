/*Printing right angled triangle*/
#include<stdio.h>
#include<stdlib.h>

using namespace std;
int main()
{  system("CLS");
   int row , col;
   printf("Enter no. of rows and columns: \n");
   scanf("%d %d \n",&row,&col);
   for(int i=row;i>0;i--){
      for(int j=1;j<=col-i+1;j++){
       printf("* ");
      }printf("\n");
   }
}