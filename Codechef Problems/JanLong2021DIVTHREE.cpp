// N --> No. of question setters
// K --> No. of problems
// D --> 

#include<bits/stdc++.h>
using namespace std;
int main(){
   int t;            //No. of test cases
   cin>>t;
   for(int i=1;i<=t;i++){
      int N , K , D;
      cin>>N>>K>>D;
      int A[N];
      for(int i=0;i<N;i++)
         cin>>A[i];
      int sum=0;
      for(int i=0;i<N;i++)
         sum+=A[i];
      if((sum/K)<=D)
         cout<<(sum/K)<<endl;
      else
         cout<<D<<endl;
   }
   return 0;
}