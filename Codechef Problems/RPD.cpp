//                                   ------------------------
//                                  | SUCCESSFULLY EXECUTED |
//                                  ------------------------

#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
   int t;             //No. of testcases
   cin>>t;                                                                                   // Time Complexity Analysis
   for(int test_case=1;test_case<=t;test_case++){                                            // Total testcases = 100
      int n;           //size of array                                                      
      cin>>n;                                                                                
      vector<int> arr(n);                                                                    
      for(int i=0;i<n;i++)                                                                   // Total Operations = 100
         cin>>arr[i];                                                                        
      // for(int i=0;i<n;i++)                                                                
      //    cout<<arr[i]<<" ";                                                               
      vector<int> ans_arr;                                                        
     int t=0;                                                                                
     for(int i=0;i<n-1;i++){                                                                 // Total operations in both loops
        for(int j=i+1;j<n;j++){                                                              //  logn means n(n-1)/2 steps  
         //   cout<<arr[i]<<" "<<arr[j]<<endl;                                               //
           ans_arr[t]=(arr[i]*arr[j]);                                                       //
         //   cout<<ans_arr[t]<<" ";                                                         //
           t++;
        }
     }
   //   for(int i=0;i<ans_arr.size();i++)
   //    cout<<ans_arr[i]<<" ";                                                           //DEBUGING
      // cout<<endl;
     int max_sum=INT_MIN;
     for(int i=0;i<ans_arr.size();i++){
      //   cout<<ans_arr[i]<<endl;
        
            int n=ans_arr[i];
            int sum=0;
            while(n>0){
               int rem=n%10;                                                             //Number converted to single digit
               sum+=rem;
               n/=10;
            }
            // cout<<sum<<endl;
            max_sum=max(max_sum,sum);
         // cout<<max_sum<<endl;
     }
     cout<<max_sum<<endl;
     cout<<endl<<endl;
   }
   return 0;
}