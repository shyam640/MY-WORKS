// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
//     int toggleBits(int N , int L , int R) {
//         return ((1<<R)-1)^((1<<(L-1))-1);
//     }
    
    int toggleBits(int N,int L,int R){
        int i=1;
        i<<=(L-1);
        while(L<=R){
            N^=i;
            i<<=1;
            L++;
        }
        return N;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,L,R;
        
        cin>>N>>L>>R;

        Solution ob;
        cout << ob.toggleBits(N,L,R) << endl;
        // cout<<endl;cout<<endl;
    }
    return 0;
}  // } Driver Code Ends