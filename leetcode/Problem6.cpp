// Problem 6 : https://leetcode.com/problems/remove-element/

/* 

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // I will discuss two methods here
        // Method 1
        // we got vector as reference so we need to change in it only
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val)
                temp.push_back(nums[i]);
        }
        nums.resize(temp.size());
        nums=temp;
        return nums.size();
    }
};

 */