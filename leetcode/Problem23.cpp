// Problem 23 : https://leetcode.com/problems/to-lower-case/

/* 

class Solution {
public:
    string toLowerCase(string str) {
        // Method 1
        // for(int i=0;i<str.length();i++){
        //     if(str[i]>='A' and str[i]<='Z')
        //         str[i]=str[i]+32;
        // }
        // Method 2
        transform(str.begin(),str.end(),str.begin(),::tolower);
        return str;
    }
};

// To simple let do in two methods

// I think this should work

// Time Complexity is O(n) 


 */