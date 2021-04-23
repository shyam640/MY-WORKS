// Problem 28 : https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

/* 
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int cnt=0;
            while(nums[i]){
                nums[i]/=10;
                cnt++;
            }
            if(cnt%2==0)
                ans++;
        }
        return ans;
    }
    
};

// Time complexity O(nLogM)  

 */