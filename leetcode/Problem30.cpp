// Problem 33 : https://leetcode.com/problems/increasing-decreasing-string/

/* 
class Solution {
public:
    string sortString(string s) {
       string ans="";
        vector<int> temp(26,0);
        for(char c:s)
            temp[c-'a']++;
        while(ans.length()<s.length()){
            for(int i=0;i<26;i++){          // Increment
                if(temp[i]){
                    ans+='a'+i;
                    temp[i]--;
                }
            }
            for(int i=25;i>=0;i--){         // Decrement
                if(temp[i]){
                    ans+='a'+i;
                    temp[i]--;
                }
            }
        }
        return ans;
    }
};

// Time complexity is O(n*26)    


 */