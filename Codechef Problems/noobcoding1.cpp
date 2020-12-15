#include<iostream>
#include<stdlib.h>

using namespace std;
int main(){
   system("CLS");
   int t;            //No. of testcases
   cin>>t;
   int term;
   for(int test_case=1;test_case<=t;test_case++){
      int n;        //Nth term
      cin>>n;
      term=((n-1)*(n-1)+(n*n*n));
      cout<<term<<endl;
   }
   return 0;
}