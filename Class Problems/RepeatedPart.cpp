#include<bits/stdc++.h>
#include<string>
using namespace std;

class Solution{
	public:
	string fractionToDecimal(int numerator, int denominator) {
	    string ans="";
	    int n=numerator;
	    int d=denominator;
	    int q=n/d;
	    int r=n%d;
	    map<int,int> mp;
	    ans.append(to_string(q));
	     if(r==0 && mp.find(r)==mp.end())
	        return ans;
        else{
            ans.append(".");
            while(r!=0){
               if(mp.find(r)!=mp.end()){
                  int len=mp[r];
                  ans.insert(len,"(");
                  ans.append(")");
                  break;
               }
               else{
                  mp[r]=ans.length();
                  r*=10;
                  q=r/d;
                  r=r%d;
                  
                  ans+=to_string(q);
                  
               } 
            }
            
        }
        return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int numerator, denominator;
		cin >> numerator >> denominator;
		Solution ob;
		string ans = ob.fractionToDecimal(numerator, denominator);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends