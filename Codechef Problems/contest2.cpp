#include<iostream>
#include<stdlib.h>

using namespace std;
int main(){
   system("CLS");
   int t;
   cin>>t;
   for(int test_case=1;test_case<=t;test_case++){
      int nrows , ncols;
      cin>>nrows>>ncols;
      int arr[nrows][ncols];
      for(int i=0;i<nrows;i++){
         for(int j=0;j<ncols;j++){
            cin>>arr[i][j];
         }
      }
      for(int i=nrows-1;i>=0;i--){
         for(int j=0;j<ncols;j++){
           cout<<arr[i][j]<<" ";
         }cout<<" ";
      }
      
   }  
   
   return 0;
}