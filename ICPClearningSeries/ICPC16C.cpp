//              -------------------------
//              | SUCCESSFULLY EXECUTED |
//              -------------------------
#include<bits/stdc++.h>
using namespace std;
int main(){
   int t;             //No. of test cases
   cin>>t;
   for(int test_case=1;test_case<=t;test_case++){
      int d;            //Given integer
      cin>>d;
      int n=d+1;
      int temp=d%9;
      temp++;
      cout<<min(n,temp)<<endl;
   }
}