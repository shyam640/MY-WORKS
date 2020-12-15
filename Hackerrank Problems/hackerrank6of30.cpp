#include<iostream>
#include<stdlib.h>

using namespace std;
int main(){
   system("CLS");
   int t;
   cin>>t;
   for(int test_case=0;test_case<t;test_case++){
      string s1 ;
      cin>>s1;
      for(int i=0;i<s1.length();i++){
         if(i%2==0){
            cout<<s1[i];
         }
      }cout<<" ";
      for(int i=0;i<s1.length();i++){
         if(i%2!=0){
            cout<<s1[i];
         }
      } 
     cout<<endl;
   }
   return 0;
}