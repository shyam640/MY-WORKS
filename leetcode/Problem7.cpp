// Problem 7 : https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/


/* 
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // Applying brute force approach
        vector<bool> ans;
        // finding maximum candy present in the array
        int max_candy = *max_element(candies.begin(),candies.end()); 
        
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies >= max_candy)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};

// SO in this we are comparing students next to it so no problem direct solution
// TIme COmplexity
// one loop of no. of candies so O(N) is time complexity

 */
