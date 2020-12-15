#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

int main(){
   system("CLS");
   int t ;
   cin>>t;
   for(int test_case=1;test_case<=t;test_case++){
      int n;
      cin>>n;
      string s , s2;
      cin>>s;
      int a = (s.length());
      char s1 = s[a-1];
      s.erase(a-1 , a);
      s2 = s;
      int flag=0;
      for(int i=0;i<s2.length();i++){
         if(s1==s2[i]){
             flag=1;
         }
      }
      if(flag==1){
         cout<<"YES"<<endl;
      }else{
         cout<<"NO"<<endl;
      }
   }
   return 0;
}