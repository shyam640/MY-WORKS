#include<bits/stdc++.h>
using namespace std;
int main(){
   int t;     // test case
   cin>>t;
   while(t--){
      string s;
      cin>>s;
      int grps_cnt=0;
      for(int i=0;i<s.length();i+=2){
         if(s[i]=='1' and s[i+1]=='1')
            grps_cnt++;
         else if(s[i]=='1')
            grps_cnt++;
         else if(s[i+1]=='1')
            grps_cnt++;
      }
      cout<<grps_cnt<<endl;
   }
}