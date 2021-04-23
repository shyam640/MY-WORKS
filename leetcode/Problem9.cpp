// Problem 9 :  https://leetcode.com/problems/jewels-and-stones/

/* 

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans=0;
        for(int i=0;i<jewels.size();i++){
            for(int j=0;j<stones.size();j++){
                if(jewels[i]==stones[j])
                    ans++;
            }
        }
        return ans;
    }
};

// Constrains are small so can go with simple method
 */

