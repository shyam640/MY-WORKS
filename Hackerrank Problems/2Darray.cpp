#include<iostream>
#include<stdlib.h>

using namespace std;
int main(){
   system("CLS");
   int t;                //No. of testcases
   cin>>t;
   for(int i=1;i<=t;i++){
      int n , c;        //No. of elephants and No. of candies
      cin>>n>>c;
      int arr[n];
      
      for(int i=0;i<n;i++){
         cin>>arr[i];
      }
      int sum=0;
      for(int i=0;i<n;i++){
         sum+=arr[i];
         
      }
      if(sum<=c){
         cout<<"Yes"<<endl;
      }else
      {
         cout<<"No"<<endl;
      }
      
   }
}