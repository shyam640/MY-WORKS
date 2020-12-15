/*printing solid rectangle*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
   system("CLS");
   int n;
   printf("Enter the Number :\n");
   scanf("%d \n",&n);
   for(int i=1;i<=n;i++)
   {
   for(int j=1;j<=n;j++){
   printf(" * ");
   }printf("\n");
   
   }
   return 0;
}