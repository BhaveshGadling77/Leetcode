class Solution {
public:
    // Recursion
    // int helper(int i, int j, vector<int>&nums) {
    //     if (i > j) 
    //         return 0;
        
    //     int maxi = INT_MIN;
    //     for (int indx = i; indx <= j; indx++) {
    //         int cost = nums[i-1] * nums[indx] * nums[j+1] 
    //                 + helper(i, indx - 1, nums)
    //                 + helper(indx + 1, j, nums);

    //         maxi = max(cost, maxi);
    //     }
    //     return maxi;
    // }

    //memoization
    int helper(int i, int j, vector<int>&nums, vector<vector<int>>&dp) {
        if (i > j) 
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        int maxi = INT_MIN;
        for (int indx = i; indx <= j; indx++) {
            int cost = nums[i-1] * nums[indx] * nums[j+1] 
                    + helper(i, indx - 1, nums, dp)
                    + helper(indx + 1, j, nums, dp);

            maxi = max(cost, maxi);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>>dp(n + 1, vector<int>(n+ 1, -1));
        return helper(1, n, nums, dp);
    }
};