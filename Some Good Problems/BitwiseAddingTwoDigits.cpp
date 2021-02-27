// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    int SimpleSum(int a,int b){
        while(b--){
            a++;
        }
        return a;
    }
    int RecursiveBitSum(int a , int b)
    {
        int add,carry;
        if(b==0)
            return a;
        add=a^b;
        carry=(a&b)<<1;
        return RecursiveBitSum(add,carry);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a,b;
        cin >> a>>b;
        
        Solution ob;
        cout<< ob.SimpleSum(a,b) <<"\n\n";
        cout<< ob.RecursiveBitSum(a,b) <<"\n";
        cout<<"\n\n\n\n"
    }
    return 0;
}
  // } Driver Code Ends