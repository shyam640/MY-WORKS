 //          -----------------------
 //         | SUCCESSFULLY EXECUTED |
 //          -----------------------
#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;
int main(){
   system("CLS");
   int t ;
   cin>>t;
   for(int test_case=1;test_case<=t;test_case++){
      string s;
      int count=0;
      cin>>s;
      if(s=="xx" || s=="yy"){
         cout<<0<<endl;
      }else if(s=="xy" || s=="yx"){
         cout<<1<<endl;
      }
      
      else
      {
         for(int i=0;i<s.length();i+=1){
            if((s[i] == 'x' && s[i+1]=='y') || (s[i] == 'y' && s[i+1] == 'x')){
               count+=1;
               i+=1;
            }else{
               continue;
            }
         }
        cout<<count<<endl;
      }
      
   }
   return 0;
}