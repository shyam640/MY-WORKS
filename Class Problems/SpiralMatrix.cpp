/* Program to print an array into spiral form (means round inside round) */


#include<bits/stdc++.h>
using namespace std;

vector<int> Spiral(vector<vector<int>> &arr,int n,int m){
   vector<int> ans;
   // for(int i=0;i<n;i++){
   //    for(int j=0;j<m;j++){
   //       cout<<arr[i][j]<<" ";
   //    }cout<<endl;
   // }
   int r_st_pt=0,r_end_pt=n,c_st_pt=0,c_end_pt=m;
while((r_st_pt<r_end_pt) and (c_st_pt<c_end_pt)){
      for(int i=c_st_pt;i<c_end_pt;i++)          // 00 01 02       (4 9 7)
         ans.push_back(arr[r_st_pt][i]);
      // for(int i=0;i<ans.size();i++)
      //    cout<<ans[i]<<" ";
      // cout<<endl;
      
      for(int i=r_st_pt+1;i<r_end_pt-1;i++)         // 12 22        (8 1)
         ans.push_back(arr[i][c_end_pt-1]);
      for(int i=0;i<ans.size();i++)
         cout<<ans[i]<<" ";
      cout<<endl;
     
      for(int i=c_end_pt-1;i>c_st_pt;i--)          // 21            () 
         ans.push_back(arr[r_end_pt-1][i]);
      // for(int i=0;i<ans.size();i++)
      //    cout<<ans[i]<<" ";
      // cout<<endl;
      
      for(int i=r_end_pt-1;i>r_st_pt;i--)             // 20 
         ans.push_back(arr[i][c_st_pt]);
      // for(int i=0;i<ans.size();i++)
      //    cout<<ans[i]<<" ";
      // cout<<endl;
      r_st_pt++; r_end_pt--;c_st_pt++;c_end_pt--;
      // cout<<endl<<endl;
   }
   // for(int i=0;i<ans.size();i++)
   //    cout<<ans[i]<<" ";
   return ans;
}

int main(){
   int n,m;
   cin>>n>>m;
   vector<vector<int>> arr(n,vector<int>(m,0));
   for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
         cin>>arr[i][j];
   vector<int> res=Spiral(arr,n,m);
   for(int i=0;i<res.size();i++)
      cout<<res[i]<<" ";
}



/*  INPUT ARRAY 
 
      Sample Input 1 :-
         5 5
         4 5 1 8 7
         2 3 5 3 6
         7 2 6 8 2
         3 6 5 9 3
         2 5 3 9 3
      Output :-
         4 5 1 8 7 6 2 3 3 9 3 5 2 3 7 2 3 5 3 8 9 5 6 2 6           This output is correct

      Sample Input 2 :-
         3 2
         1 5
         2 0
         3 7
      Output :- The output comming is wrong . Its correct output is     1 5 0 7 3 2

      Sample Input 3 :-
         3 1
         1
         2
         3
      Output :- The output comming is wrong . Its correct output is     1 2 3

*/