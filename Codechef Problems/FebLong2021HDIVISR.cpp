#include<bits/stdc++.h>
using namespace std;
int main(){
   int N;
   cin>>N;
   int i;
   for(i=10;i>0;i--){
      if(N%i==0)
         break;
   }
   cout<<i<<endl;
}