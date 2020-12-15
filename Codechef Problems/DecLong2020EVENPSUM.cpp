//            ----------------
//           |PARTIAL COMPLETE|
//            ----------------
#include<iostream>
#include<stdlib.h>

using namespace std;
int main(){
   system("CLS");
   int t;         //No. of test cases
   cin>>t;
   for(int test_case=1;test_case<=t;test_case++){
      int A , B;
      cin>>A>>B;
      int count=0;
      for(int X=2;X<=A;X+=2){
        for(int Y=2;Y<=B;Y+=2){
            if((X+Y)%2==0){
               count+=1;
            }else{
               continue;
            }
        }
      }
      for(int X=1;X<=A;X+=2){
        for(int Y=1;Y<=B;Y+=2){
            if((X+Y)%2==0){
               count+=1;
            }else{
               continue;
            }
        }
      }
      cout<<count<<endl;
   }
   return 0;
}