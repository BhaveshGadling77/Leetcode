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
        // vector<vector<int>>dp(n, vector<int>(n + 1, -1));
        // return helper(0, -1, nums, dp);

        //tabulation

        // vector<vector<int>>dp(n +1, vector<int>(n + 1, 0));

        // for (int indx = n-1; indx >= 0; indx--) {
        //     for (int prev = indx - 1; prev >= -1; prev--) {
        //         int notTake = dp[indx + 1][prev+1];
        //         int take = INT_MIN;
        //         if (prev == -1 || nums[indx] > nums[prev])
        //             take = 1 + dp[indx + 1][indx + 1];
                
        //         dp[indx][prev +1] = max(notTake, take);
        //     }
        // }

        //space optimization.
        // vector<int>after(n + 1, 0);
        // vector<int>curr(n + 1, 0);
        // for (int indx = n-1; indx >= 0; indx--) {
        //     for (int prev = indx - 1; prev >= -1; prev--) {
        //         int notTake = after[prev+1];
        //         int take = INT_MIN;
        //         if (prev == -1 || nums[indx] > nums[prev])
        //             take = 1 + after[indx + 1];
                
        //         curr[prev +1] = max(notTake, take);
        //     }
        //     after = curr;
        // }
        // return curr[0];

        // 1 D optimization code
        vector<int>dp(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] > nums[prev]) {
                    dp[i] = max(1 + dp[prev], dp[i]);
                }
            }
            maxi = max(dp[i], maxi);
        }
        return maxi;
    }
};