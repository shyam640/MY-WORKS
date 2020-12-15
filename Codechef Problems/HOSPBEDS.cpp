#include<iostream>
#include<stdlib.h>

using namespace std;
int main(){
   system("CLS");
   int t;
   for(int test_case=1;test_case<=t;test_case++){
      int n;
      cin>>n;
      int a[n];
      for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
            cin>>a[j];
         }
      }

      for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
            cout<<a[j];
         }
      }
      
   }   
   return 0;
}