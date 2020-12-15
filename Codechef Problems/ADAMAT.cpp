// N -->No. of rows and columns
// 

#include<iostream>
#include<stdlib.h>

using namespace std;
int main(){
   system("CLS");
   int t;        //No. of test cases
   cin>>t;
   for(int test_case=1;test_case<=t;test_case++){
      int N;    // Rows and Columns
      cin>>N;
      int mat[N][N];
      for(int i=0;i<N;i++){
         for(int j=0;j<N;j++){
             cin>>mat[i][j];
         }
      }
   }
}