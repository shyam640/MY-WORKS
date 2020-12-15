/**/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	system("CLS");
	int n,i,j,k;
	printf("Enter the number : ");
	scanf("%d",&n);
	k=k-2;
	for(i=n+1;i>=1;--i){
		for(j=1;j<=n+1-i;++j)
			printf("%d ",k);
			printf("\n");
	}
}
