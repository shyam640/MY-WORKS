// Problem 27 : https://leetcode.com/problems/unique-morse-code-words/

/* 
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> temp = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        vector<string> concatArr;
        for(int i=0;i<words.size();i++){
            string cct="";
            for(int j=0;j<words[i].size();j++){
                cct+=temp[words[i][j]-'a'];
            }
            concatArr.push_back(cct);
        }
        sort(concatArr.begin(),concatArr.end());
        concatArr.erase(unique(concatArr.begin(),concatArr.end()),concatArr.end());
        return concatArr.size();
    }
};

// Time Conplexity O(n*m) 


 */