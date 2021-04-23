// Problem 12 : https://leetcode.com/problems/shuffle-string/

/* 
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
       string ans="";
        char temp[s.length()];
        for(int i=0;i<indices.size();i++)
            temp[indices[i]] = s[i];
        for(int i=0;i<s.length();i++)
            ans+=temp[i];
        return ans;
    }
};

// we need to arrange string characters at position in indices
// Time Complexity is O(N)  n = size of indices

 */
