// Problem 24 : https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/


/* 
class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> arr = nums;                // using it so actual array do not change
        int minopr=0;
        for(int i=1;i<nums.size();i++){
            if(arr[i]>arr[i-1])
                continue;
            else{
                minopr+=((((arr[i]-arr[i-1])>0)?(arr[i]-arr[i-1]):(arr[i-1]-arr[i]))+1);
                arr[i]+=((((arr[i]-arr[i-1])>0)?(arr[i]-arr[i-1]):(arr[i-1]-arr[i]))+1);
            }
        }
        return minopr;
    }
};

// Time Complexity is O(n)   


 */