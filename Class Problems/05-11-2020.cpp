/*Printing fibonacci series*/
#include <stdio.h>


int main()
{

int n;
scanf("%d",&n);
int t1=0;
int t2=1;
printf("%d %d",t1,t2);
for(int i=2;i<n;i++){
int next_term=t1+t2;
printf(" %d",next_term);
t1=t2;
t2=next_term;
}

return 0;
}