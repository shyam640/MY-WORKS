#include<bits/stdc++.h>
using namespace std;

int main(){
   int n;         //No. of elements in array
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)
      cin>>arr[i];
   float sum=0;
   for(int i=0;i<n;i++)
      sum+=arr[i];
   float mean=sum/n;
   float median=0;
   if(n%2==0){
      int x=arr[n/2];
      int y=arr[(n+2)/2];
      cout<<x<<" "<<y<<endl;
      median=(x+y)/2;
   }
   else
      median=arr[n/2];

   cout<<mean<<setprecision(1)<<"\n"<<median<<setprecision(1)<<"\n";

   return 0;
}

