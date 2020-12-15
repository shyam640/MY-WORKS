#include<iostream>
#include<stdlib.h>

using namespace std;
int main(){
   system("CLS");
   int n;
   cin>>n;
   for(int i=1;i<=n;i++){
      for(int j=1;j<n;j++){
         if(j<n-i+1){
            cout<<" ";
         }else if(j>n-i+1){
         cout<<" ";
         }else
         {
            cout<<"* ";
         }
         if(i==n){
            cout<<"*";
         }     
         if(j==2*n-i){
            cout<<" *";
         }    
      }cout<<endl;
   }
   return 0;
}