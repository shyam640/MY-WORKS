// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends


//User function Template for C++


class Solution
{
public:
    string smallestnum(string N)
    {
        sort(N.begin(),N.end());
        int count=0;
        for(int i=0;i<N.size();i++){
           if(N[i]=='0'){
              count++;
              continue;
           }
           else
           {
              break;
           }
         }
         // cout<<count<<endl;
         int temp=N[count];
         N[count]=N[0];
         N[0]=temp;
      //   for(int i=0;i<N.size();i++)
      //      cout<<N[i];
      //    cout<<endl;
        return N;

    }
};



// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string N;
        cin >>N;
        Solution ob;
        string ans = ob.smallestnum(N);
        cout << ans << endl;
    }
    return 0;
}
  // } Driver Code Ends