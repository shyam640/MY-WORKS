#include<bits/stdc++.h>
using namespace std;
int main(){
   int x;
   float y;
   cin>>x>>y;
   int temp=(int) y;
   // cout<<x<<" "<<temp<<" "<<y<<endl;
   
   if(x%5==0 and temp>x)
      cout<<fixed<<setprecision(2)<<(y-x-0.5)<<endl;
   else if(x%5!=0 or temp<x)
      cout<<fixed<<setprecision(2)<<y<<endl;
   
}