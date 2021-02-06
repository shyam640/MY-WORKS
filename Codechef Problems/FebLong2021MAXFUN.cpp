#include<bits/stdc++.h>
#include<vector>
using namespace std;
long long int sum(int x,int y,int z){
   return ((y-x)+(z-y)+(z-x));
}

int main(){
   int t;            //No. of test cases
   cin>>t;
   while(t--){
      long long int n;      //size of array
      cin>>n;
      vector<long long> arr(n);
      for(int i=0;i<n;i++)
         cin>>arr[i];
      stable_sort(arr.begin(),arr.end());
      long long int max_ans=0;
      for(int i=1;i<n-1;i++){
         long long int temp=sum(arr[i-1],arr[i],arr[i+1]);
         max_ans=max(max_ans,temp);
      }
      cout<<max_ans<<endl;
   }
}