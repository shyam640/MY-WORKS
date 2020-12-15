#include<iostream>


using namespace std;
int main(){
   
   int t;
   cin>>t;
   for(int test_case=1;test_case<=t;test_case++){
      long  int TS; long int JS = 0;
      cin>>TS;
      if(TS==1 || TS==2){
          cout<<JS<<endl;
      }else{
            if(TS%2==0){
               while(TS%2==0){
                  TS/=2;
               }
            cout<<TS/2<<endl;
            }
           else{
              cout<<(TS-1)/2<<endl;
               }
         
      }
   }
   return 0;
}