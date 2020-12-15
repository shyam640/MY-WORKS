//ada and dishes
#include<iostream>
#include<stdlib.h>

using namespace std;
int main(){
   system("CLS");
   int t;        //No. of testcases
   cin>>t;
   int n;        //No. of dishes
   for(int test_case=1;test_case<=t;test_case++){
      cin>>n;
      int min[n];
      for(int i=0;i<n;i++){
         cin>>min[i];
      }
      for(int i=0;i<n-1;i++){
         for(int j=i;j<n;j++){
            if(min[j]>min[i]){
               int temp=min[i];
               min[i]=min[j];
               min[j]=temp;
            }
         }
      }
      int b1=0,b2=0;
      for(int i=0;i<n;i++){
         if(b1<b2){
         b1+=min[i];
         
         }else{
            b2+=min[i];
         }
         
      }
      cout<<max(b1,b2)<<endl;
   }
      return 0;
}