//                  ----------------------
//                 | SUCCESSFULLY EXECUTED |
//                  ----------------------
#include<bits/stdc++.h>

using namespace std;

int main(){
   system("CLS");
   int t;        //No. of Test cases
   cin>>t;
   for(int test_case=1;test_case<=t;test_case++){
      int n;
      cin>>n;
      int arr[n];
      for(int i=0;i<n;i++){
         cin>>arr[i];
      }
      int even=0 , odd=0;
      for(int i=0;i<n;i++){
         if(arr[i]%2==0)
         even++;
         else
         odd++;
      }
      
      if(n==1)
      cout<<"0"<<endl;
      else if((even+odd)==1)
      cout<<"0"<<endl;
      else if(even>odd && even>0 && odd>0)
      cout<<(even+((odd-1)*2))<<endl;
      else if(odd>=even && even>0 && odd>0)
      cout<<(odd+((even-1)*2))<<endl;
      
   }return 0;
}