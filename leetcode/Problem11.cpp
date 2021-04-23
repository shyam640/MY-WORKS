// Problem 11 : https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

/* 

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(nums[i]>nums[j] and i!=j)
                    ans[i]++;
            }
        }
        return ans;
    }
};

// Simple constrain so using simple method i.e. brute force

 */
