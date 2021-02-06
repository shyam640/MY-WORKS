#include<iostream>
#include<stdlib.h>
using namespace std;
void Sort(int a[],int size){
  
   for(int i=0;i<size-1;i++){
      for(int j=i+1;j<size;j++){
         if(a[j]<a[i]){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            
         }
      }
   }
}

int main(){
   system("CLS");
   int n;       // Size of array
   cin>>n;
   int arr[n]; int temp_arr[n];
   for(int i=0;i<n;i++){
     cin>>arr[i];
     temp_arr[i]=arr[i];
   }
   Sort(arr,n);
   int s_p=-1 , e_p=-1 , count=0;   //Start_point End_point count
   for(int i=0;i<n;i++){
      if(temp_arr[i]!=arr[i]){
         
      }
   }
   return 0;
}