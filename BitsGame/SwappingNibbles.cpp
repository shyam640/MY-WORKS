// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int swapNibbles(unsigned char x){
        unsigned char a=x>>4;
        unsigned char b=x<<4;
        return a|b;
    }
    
    // int swapNibbles(unsigned char x){
    //     return ((x/16)+((x%16)*16));
    // }
    
    // int swapNibbles(unsigned char x){
    //     return x>>4|(x&15)<<4;
    // }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.swapNibbles(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends