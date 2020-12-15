#include<iostream>
#include<stdlib.h>

using namespace std;
int main(){
   system("CLS");
   int t;
   cin>>t;
   for(int test_case=1;test_case<=t;test_case++){
   int n;
   cin>>n;
   int num=1 , sum=11;
   int i=2;
     while(i>1){
        sum=sum+i*10-1;
        if(sum>=n){
         cout<<"Case #"<<test_case<<": "<<i+1<<endl;
         break;
        }else
        {
           i++;
        }
        
      }
   }
}