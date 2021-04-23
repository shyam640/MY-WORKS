// Problem 21 : https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

/* 

class Solution {
public:
    int maxDepth(string s) {
        int maxDpth = 0;
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                st.push(s[i]);
            else if(s[i]==')')
                st.pop();
            maxDpth = (maxDpth<st.size())?st.size():maxDpth;
        }
        return maxDpth;
    }
};

 */
