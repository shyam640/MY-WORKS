#include<bits/stdc++.h>
using namespace std;
int main(){
   int t;              //No. of test cases
   cin>>t;
   for(int test_case=1;test_case<=t;test_case++){
      int x1 , y1 , x2 , y2;
      cin>>x1>>y1>>x2>>y2;
      if((x2-x1)==0){
         if(y2>y1)
            cout<<"up"<<endl;
         else
            cout<<"down"<<endl;
      }
      else if((y2-y1)==0){
         if(x2>x1)
            cout<<"right"<<endl;
         else
            cout<<"left"<<endl;
      }
      else
         cout<<"sad"<<endl;
   }
   return 0;
}