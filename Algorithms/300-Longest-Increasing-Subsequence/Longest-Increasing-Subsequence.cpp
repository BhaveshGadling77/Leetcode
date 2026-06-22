class Solution {
public:
    int helper(int indx, int prev, vector<int>&nums, vector<vector<int>>&dp) {
        if (indx == nums.size()) 
            return 0;
        
        if (dp[indx][prev + 1] != -1)
            return dp[indx][prev + 1];
        
        int notTake = helper(indx + 1, prev, nums, dp);
        int take = INT_MIN;
        if (prev == -1 || nums[indx] > nums[prev])
            take = 1 + helper(indx + 1, indx, nums, dp);

        return dp[indx][prev +1] = max(notTake, take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n + 1, -1));
        return helper(0, -1, nums, dp);
    }
};