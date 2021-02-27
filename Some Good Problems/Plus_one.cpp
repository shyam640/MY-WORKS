// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> increment(vector<int> arr ,int N) {
       for(int i=N-1;i>=0;i--){
           if(arr[i]!=9){
               arr[i]+=1;
               return arr;
           }
           else if(arr[i]==9){
               arr[i]=0;
           }
       }
        vector<int> myarr(N+1);
       int j;
       for(j=N;j>=0;j--){
           myarr[j]=arr[j-1];
       }
       myarr[0]=1;
       return myarr;4
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        char c;
        
        cin>>N;
        vector<int> arr(N);
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> res = ob.increment(arr,N);
        for(int i: res)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends