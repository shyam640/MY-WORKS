// Problem 8 : https://leetcode.com/problems/number-of-good-pairs/

/* 

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j])
                    ans++;
            }
        }
        return ans;
    }
};

// Simple constraint so brute force approach

 */
