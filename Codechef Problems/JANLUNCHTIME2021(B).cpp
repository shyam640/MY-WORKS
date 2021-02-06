//                         ------------------------
//                        | SUCCESSFULLY EXECUTED |
//                        ------------------------
          
#include<bits/stdc++.h>
using namespace std;
int main(){
   int t;         //No. of test cases 
   cin>>t;
   for(int test_case=1;test_case<=t;test_case++){
      int n;
      cin>>n;
      int arr[n];
      for(int i=0;i<n;i++)
         cin>>arr[i];
      int count=0;
      for(int i=0;i<n-1;i++){
         int flag=0;
         // for(int j=i+1;j<n;j++){
         //    // cout<<arr[i]<<" "<<arr[j]<<endl;
         //    if((arr[i]-arr[j])%2==0)
         //       continue;
         //    else{
         //       flag=1;
         //       arr[j]+=1;
         //       }
         // }
         if((arr[i]-arr[i+1])%2==0)
            continue;
         else {
            if(arr[i+2]%2==0){
               flag=1;
               arr[i+1]+=1;
            }else{
               flag=1;
               arr[i]+=1;
            }
         }
         if(flag==1)
            count++;
      }
      cout<<count<<endl;
   }
}