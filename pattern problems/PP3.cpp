/*Printing inverted right angle triangle*/
#include<stdio.h>
#include<stdlib.h>

using namespace std;
int main(){
  system("CLS");
  int row,col;
  printf("Enter no. of rows and columns: \n");
  scanf("%d %d \n",&row , &col);
  for(int i=1;i<=row;i++){
    for(int j=col-i+1;j>0;j--){
      printf("* ");
    }printf(" ");
    printf("\n");
  }
}