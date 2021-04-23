// Problem 18 : https://leetcode.com/problems/create-target-array-in-the-given-order/

/* 
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            if(index[i]>=i){
                ans[index[i]] = nums[i];
            }else{
                int prev = ans[index[i]];
                ans[index[i]] = nums[i];
                // moving rest element one step forward
                for(int j=index[i]+1;j<nums.size();j++){
                    int nxt = ans[j];     // storing next element;
                    ans[j] = prev;
                    prev = nxt;                 // now next element becomes previous element
                }
            }
        }
        return ans;
    }
};

// Simple constraints so simple method

// Time Complexity is O(nlogm)   n = size of nums logm for moving elements forward in worst case 
// it will be O(N*M)   


 */