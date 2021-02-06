#include<bits/stdc++.h>
using namespace std;
int main(){
   int t;     //No. of test cases
   cin>>t;
   for(int i=1;i<=t;i++){
      int n;      //size of array
      cin>>n;
      int arr[n];
      for(int i=0;i<n;i++)
         cin>>arr[i];
      sort(arr,arr+n);
      // for(int i=0;i<n;i++)
      //    cout<<arr[i]<<" ";
      cout<<arr[0]+arr[1]<<endl;
   }
   return 0;
}