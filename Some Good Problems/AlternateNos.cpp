// { Driver Code Starts
#include <bits/stdc++.h>
#include<list>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    vector<int> pst_arr;
	    vector<int> neg_arr;
	    for(int i=0;i<n;i++){
	        if(arr[i]>=0)
	            pst_arr.push_back(arr[i]);
            if(arr[i]<0)
                neg_arr.push_back(arr[i]);
	    }
	    for(int i=0,j=0,k=0;i<n;){
	        if(j<pst_arr.size())
	            arr[i++]=pst_arr[j++];
            if(k<neg_arr.size())
                arr[i++]=neg_arr[k++];
	    }
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends