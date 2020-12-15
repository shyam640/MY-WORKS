#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
int main(){
   system("CLS");
   int t;
   for(int test_case=1;test_case<=t;test_case++){
      int n;        //NO. of students
      cin>>n;
      int arr1[n];
      for(int i=0;i<n;i++){
         cin>>arr1[i];
      }
      int arr2[n];
      for(int j=0;j<n;j++){
         cin>>arr2[j];
      }
      int time_diff[n];
      for(int i=0;i<n;i++){
         time_diff[i]=arr1[i+1]-arr1[i];
      }
     for(int k=0;k<n;k++){
        cout<<time_diff[k]<<" ";
     }
   }
   return 0;
}