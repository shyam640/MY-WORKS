// Problem 16 : https://leetcode.com/problems/decode-xored-array/

/* 

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);            // A ^ B = C then C ^ first = second  and 
        for(int i=0;i<encoded.size();i++){   //second ^ first = third and third ^ second = fourth
            ans.push_back(ans[i]^encoded[i]);       // xoring with previous in ans array
        }
        return ans;
    }
};


// Simple constraints so simple method
// In this we need to do reverse process we need to find array whose simultaneous element's 
// xor is encoded array

// Time Complexity is O(N) n = encoded array size

 */