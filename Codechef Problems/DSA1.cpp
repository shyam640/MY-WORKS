#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<string>
using namespace std;
int main(){
   system("CLS");
   int t;
   cin>>t;
    string s1;
   for(int test_case=1;test_case<=t;test_case++){
      cin>>s1;
      int x = stoi(s1);
      while(s%10==0){
         s=s/10;
      }goto reverse;
      else
      {
         goto reverse;
      }
      reverse:
         for(int i=s1.length()-1;i>=0;i--){
      
          cout<<s1[i];
      
      
         }cout<<endl;
      
   }
   
   return 0;
}