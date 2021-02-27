// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // long long int convertEvenBitToZero(long long int n) {
    //     long long int t=0;
    //     long long int new_num=0;
    //     while(n){
    //         int rem=n%2;
    //         if(t%2!=0)
    //             new_num+=(rem*pow(2,t));
    //         n/=2;
    //         t++;
    //     }
    //     return new_num;
    // }
    
    long long int convertEvenBitToZero(long long int n){
        return (n&0xAAAAAAAAAAAAA);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.convertEvenBitToZero(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends