#include<iostream>
#include<stdlib.h>
#include<stdio.h>
int main()
{
    system("CLS");
    int n,i,prod;
    scanf("%d",&n);
    for(i=1;i<=10;i++)
    {
        prod=n*i;
        printf("%d * %d = %d \n",n , i , prod);
    }
}