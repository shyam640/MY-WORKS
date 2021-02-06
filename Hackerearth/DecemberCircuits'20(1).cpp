#include<bits/stdc++.h>

using namespace std;

int main(){
   int t;       //No. of test cases
   cin>>t;
   for(int i=0;i<t;i++){
      int x;      //size of array
      cin>>x;
      int arr[x];
      for(int i=0;i<x;i++)
         cin>>arr[i];
      int sum=0;
      for(int i=0;i<x;i++){
      int count=0;
         for(int j=x-1;j>i;j--){
            if(arr[i]==arr[j]){
               count=(j-i);
               break;
            }
         }
         sum+=count;
      }
      cout<<sum<<endl;
   }
}