#include<bits/stdc++.h>
using namespace std;
int main(){
   int t;     //no. of test cases 
   cin>>t;
   for(int i=1;i<=t;i++){
      int n;
      cin>>n;
      int A[n] , B[n];
      for(int i=0;i<n;i++)
         cin>>A[i];
      for(int i=0;i<n;i++)
         cin>>B[i];
      int count=0;
      if(A[0]>=B[0])
         count++;
      for(int i=1;i<n;i++){
         if((A[i]-A[i-1])<=B[i])
         count++;
         else
         continue;
      }
         cout<<count<<endl;
   }
   return 0;
}