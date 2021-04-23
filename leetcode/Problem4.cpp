// Problem 4 : https://leetcode.com/problems/3sum/


/* 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        // Sorting array to group same number so we can skip them 
        sort(nums.begin(),nums.end());
        // Transversing whole nums array
        for(int i=0;i<nums.size();i++){
            // Keeping starting and ending pointer
            int st=i+1,end=nums.size()-1;        // a,b
            int rightNum = -nums[i];            // -c
            // a + b + c = 0   then it is    a + b = -c
            while(st<end){
                int sum = nums[st]+nums[end];
                // Checking if sum is greater
                if(sum>rightNum)
                    end--;
                else if(sum<rightNum)
                    st++;
                else{                       // Triplet found
                    // Pushing triplet into ans array
                    ans.push_back(vector<int>{nums[i],nums[st],nums[end]});
                    // checking if duplicate no. present from left and right
                    // skipping them 
                    while(st<end and nums[st]==nums[st+1])
                        st++;
                    while(st<end and nums[end]==nums[end-1])
                        end--;
                    st++;
                    end--;
                }
            }
            // if duplicates of first element i.e. target are present
            while(i+1<nums.size() and nums[i]==nums[i+1])
                i++;
        }
        return ans;
    }
};

 */