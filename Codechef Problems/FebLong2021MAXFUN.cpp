#include<bits/stdc++.h>
#include<vector>
using namespace std;
inline long long int sum(int x,int y,int z){
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
      long long int max_element=*max_element(arr.begin(),arr.end());
      long long int min_element=*min_element(arr.begin(),arr.end());
      int result=(2*(max_element-min_element));
      cout<<result<<endl;
   }
}
