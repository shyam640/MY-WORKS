// Problem 31 : https://leetcode.com/problems/determine-color-of-a-chessboard-square/

/* 
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        vector<char> x1 = {'a','c','e','g'};
        vector<int> y1 = {'1','3','5','7'};
        vector<char> x2 = {'b','d','f','h'};
        vector<int> y2 = {'2','4','6','8'};
        int flag=0;
        if(count(x1.begin(),x1.end(),coordinates[0]) and count(y1.begin(),y1.end(),coordinates[1]))
            flag=1;
        if(count(x2.begin(),x2.end(),coordinates[0]) and count(y2.begin(),y2.end(),coordinates[1]))
            flag=1;
        return (flag==0)?true:false;
    }
};

 */