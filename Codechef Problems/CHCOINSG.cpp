//                               ------------------------
//                              | SUCCESSFULLY EXECUTED |
//                              ------------------------

#include<bits/stdc++.h>
using namespace std;

int main(){
   int t;           //No. of test cases
   cin>>t;
   while(t--){
      int n;
      cin>>n;
      if(n==1 || n==2 || n==3 || n==4 || n==5)
         cout<<"Chef"<<endl;
      else{
         if(n%6!=0)
            cout<<"Chef"<<endl;
         else
            cout<<"Misha"<<endl;
      }
   }
   return 0;
}