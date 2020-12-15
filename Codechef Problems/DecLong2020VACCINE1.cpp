// D --> days   V --> vaccines produced per day   P --> no. of vaccine required
// Constraints
//    1≤D1,V1,D2,V2≤100
//    1≤P≤1,000

#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
   system("CLS");
   int D1 , V1 , D2 , V2 , P;
   cin>>D1>>V1>>D2>>V2>>P;
   int total=V1+V2;
   int count=0;
   int new_total=0;
   do{
      new_total+=total;
      count+=1;
   }while(new_total<=P);
   cout<<count;
   return 0;
}