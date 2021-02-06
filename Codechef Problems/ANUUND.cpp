#include<bits/stdc++.h>
using namespace std;
void swap(int arr[],int i,int j){
      int temp=arr[i];
      arr[i]=arr[j];
      arr[j]=temp;
}
int main(){
   int t;     //No. of test cases
   cin>>t;
   for(int i=1;i<=t;i++){
      int n;      //size of array
      cin>>n;
      int arr[n];
      for(int i=0;i<n;i++)
         cin>>arr[i];
      for(int i=0;i<n;i++){
         if(i%2==0){
            if(arr[i]>arr[i+1]){
               swap(arr,i,i+1);
            }else{
               continue;
            }
         }else{
            if(arr[i]<arr[i+1] && i<=n-2){
               swap(arr,i,i+1);
            }else{
               continue;
            }
         }
      }
      for(int i=0;i<n;i++)
         cout<<arr[i]<<" ";
      cout<<endl;
   }
   return 0;
}