#include<iostream>
#include<stdlib.h>

using namespace std;
int main(){
   system("CLS");
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
      cin>>arr[i];   
   }
   for(int i=0;i<n-1;i++){
      
      for(int j=i;j<n;j++){
         if(arr[j]>arr[i]){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }
      
   }
   for(int i=0;i<n;i++){
         cout<<arr[i]<<" ";
      }
   return 0;
}