#include<bits/stdc++.h>
using namespace std;
int main(){
   int n,h,x;     // x-> time left
                  // H-> time needed to solve problem
                  // N-> different time zones
   cin>>n>>h>>x;
   vector<int> arr(n);
   for(int i=0;i<n;i++) cin>>arr[i];
   if(h==x)
      cout<<"YES"<<endl;
   int flag=0;
   for(int i=0;i<n;i++){
      if(arr[i]+x==h){
         flag=1;
         break;
      }
   }
   if(flag)
      cout<<"YES"<<endl;
   else
      cout<<"NO"<<endl;

}