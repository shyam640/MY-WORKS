// Problem 20 : https://leetcode.com/problems/xor-operation-in-an-array/

/* 
class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> nums;
        for(int i=0;i<n;i++)
            nums.push_back(start+2*i);
        int elmsXOR = nums[0];
        for(int i=1;i<n;i++)
            elmsXOR^=nums[i];
        return elmsXOR;
    }
};

// Time Complexity is O(n) 

 */
