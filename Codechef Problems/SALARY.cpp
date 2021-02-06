#include<bits/stdc++.h>
using namespace std;
int main(){
   int t;        //No. of test cases
   cin>>t;
   while(t--){
      if(t<0)
         break;
      int N;       //No. of workers
      cin>>N;
      int W[N];
      for(int i=0;i<N;i++)
         cin>>W[i];
      int flag=0;
      for(int i=0;i<N;i++){
         if(W[i]==W[i+1])
            flag=1;
         else{
            flag=0;
            break;
         }
      }
      
   }
}