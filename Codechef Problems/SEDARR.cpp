//                                   -------------------------
//                                   | SUCCESSFULLY EXECUTED |
//                                   -------------------------
#include<bits/stdc++.h>
using namespace std;
int main(){
   int t;          //No. of test cases
   cin>>t;
   for(int test_case=1;test_case<=t;test_case++){
      long int n,k;
      cin>>n>>k;
      long long int a[n];
      for(int i=0;i<n;i++)
         cin>>a[i];
      long long int sum=0;
      for(int i=0;i<n;i++)
         sum+=a[i];
      if(sum%k==0)
         cout<<"0"<<endl;
      else
         cout<<"1"<<endl;
   }
}