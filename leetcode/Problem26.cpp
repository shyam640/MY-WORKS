// Problem 26 : https://leetcode.com/problems/determine-if-string-halves-are-alike/

/* 
class Solution {
public:
    bool halvesAreAlike(string s) {
        int st=0,end=s.length()-1;
        int a_vowel=0,b_vowel=0;
        vector<char> arr = {'a','e','i','o','u','A','E','I','O','U'};
        while(st<=end){
            if(count(arr.begin(),arr.end(),s[st]) > 0)
                a_vowel++;
            if(count(arr.begin(),arr.end(),s[end]) > 0)
                b_vowel++;
            // cout<<a_vowel<<" "<<b_vowel<<endl;
            st++;end--;
        }
        return (a_vowel==b_vowel);
    }
};


// simple constraints so simple method
// Time complexity is O(n/2)  


 */