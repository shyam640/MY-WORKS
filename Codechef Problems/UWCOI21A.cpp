#include<iostream>

using namespace std;
int main(){
   int t;      //No. of test cases
   cin>>t;
   for(int test_case=1;test_case<=t;test_case++){
      int n;        //Integer
      cin>>n;
      if(n==1 || n==0){
         cout<<n<<" "<<n<<endl;
      }else if(n==2){
         cout<<"1"<<" "<<"2"<<endl;
      }
      else if(n%2==0){
         cout<<"2"<<" "<<n/2<<endl;
      }else{
         cout<<"1"<<" "<<n<<endl;
      }
   }
   return 0;
}