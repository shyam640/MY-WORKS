#include<bits/stdc++.h>
using namespace std;
int main(){
   int t;      // test case
   cin>>t;
   while(t--){
      int n,e,h,a,b,c;
      cin>>n>>e>>h>>a>>b>>c;
      // n-> persons
      // e-> no. of eggs
      // h-> no. of chocolate
      // a-> price of omelette
      // b-> price of chocolate milkshake
      // c-> price of chocolate bar
      pair<int,int> p1,p2,p3;
      p1.first=a;p1.second=2;
      p2.first=b;p2.second=3;
      p3.first=c;p3.second=2;
      int total_ingrdnts=e+h;
      int min_price=0;
      if(((e+h)/2)<n) cout<<"-1"<<endl;
      else{
         if(p1.first>=p2.first and p1.first>=p3.first){
            while(total_ingrdnts>p1.second){
               min_price+=p1.first;
               total_ingrdnts-=p1.second;
            }
         }
         cout<<min_price<<endl;
      }
   }
   return 0;
}