#include<bits/stdc++.h>
using namespace std;
int main(){
   int t;       // test cases
   cin>>t;
   while(t--){
      int n;         // size of arra
      cin>>n;
      vector<int> arr(n);
      for(int i=0;i<n;i++) cin>>arr[i];
      int max_elm=*max_element(arr.begin(),arr.end());
      int temp=0;
      for(int i=0;i<n;i++){
         temp+=(max_elm-arr[i]);
      }
      // cout<<temp<<endl;
      if(temp%2==0) cout<<"Second"<<endl;
      else cout<<"First"<<endl;
   }
}