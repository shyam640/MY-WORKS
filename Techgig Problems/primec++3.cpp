/*Print prime numbers in an interval*/
#include <iostream>
#include<math.h>
using namespace std;
bool isprime(int n){
   if(n==0||n==1)
   return false;
   for(int j=2;j<=sqrt(n);j++){
      if(n%j==0)
      return false;
   }return true;
}

int main()
{  system("CLS");
	int a,b;
   cin>>a;
   cin>>b;
   for(int i=a;i<=b;i++){
     if(isprime(i)==true){
        cout<<i<<endl;
     }
   }
   return 0;
}