#include<iostream>
#include<stdlib.h>

using namespace std;
int main(){
   system("CLS");
   int arr[5];
   for(int i=0;i<5;i++){
   cin>>arr[i];
   
   }
   for(int i=0;i<5;i++){
      if(arr[i]==42){
         break;
      }else
      {
         cout<<arr[i]<<endl;
      }
      
   }
   return 0;
}