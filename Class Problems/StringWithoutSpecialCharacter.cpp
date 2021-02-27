//                           -----------------------
//                          | SUCCESSFULLY EXECUTED |
//                           ------------------------

#include<bits/stdc++.h>
using namespace std;

string RemoveCharacters(string &s){
   string s1;
   for(int i=0;i<s.length();i++){
      if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z'){
         s1.push_back(s[i]);
      }
   }
   transform(s1.begin(),s1.end(),s1.begin(),::tolower);
   return s1;
}

bool ValidPalindrome(string str){
   if(str.length()==0)
      return true;
   int st_pt=0,en_pt=str.length()-1;
   // cout<<s1[en_pt]<<endl;
   while(st_pt<=en_pt){
      if(str[st_pt]!=str[en_pt])
         return false;
      st_pt++;en_pt--;
   }
   return true;
}

int main(){
   string s;
   getline(cin,s);
   s=RemoveCharacters(s);
   // cout<<s<<endl;
   cout<<ValidPalindrome(s)<<endl;
}