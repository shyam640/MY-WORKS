/*Printing right angle triangle of numbers*/
#include<iostream>
#include<stdlib.h>

using namespace std;
int main(){
   system("CLS");
   int n;
   cin>>n;
   for(int i=0;i<=n;i++){
      for(int j=1;j<=n;j++){
         if(j<=i){
            cout<<j<<" ";
         }else 
         {
            cout<<" ";
         }
      }cout<<endl;
   }
   return 0;
}   