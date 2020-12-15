#include<iostream>
#include<stdlib.h>
using namespace std;

int SumofN(int n){
   int sum=(n*(n+1))/2;
   return sum;
}

void pythagorian_triplet(int x,int y,int z){
   int a,b,c;
   if(x>y && x>z)
   { a=x;
     b=y; c=z;}
   if(y>z && y>x){
       a=y;
       b=z; c=x;
   }
   if(z>x && z>y){
       a=z;
       b=y; c=x;
   }
   int temp2=(a*a);
   if(temp2 = ((b*b)+(c*c)))
      cout<<"Pythagorian Triplet"<<endl;
   else 
      cout<<"Not a pythagorian Triplet"<<endl;
}

int main(){
   system("CLS");
   
   int num;
   cout<<"Enter no. till which we need to find sum :";
   cin>>num;
   cout<<endl;
   int ans =SumofN(num);
   cout<<"Sum is :"<<ans<<endl;
   cout<<endl;

   int num1,num2,num3;
   cout<<"Enter three numbers to be checked for pythagorian triplet:";
   cin>>num1>>num2>>num3;
   pythagorian_triplet(num1,num2,num3);
   cout<<endl;
   

}