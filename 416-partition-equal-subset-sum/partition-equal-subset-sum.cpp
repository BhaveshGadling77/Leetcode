class Solution {
public:
    //recursion
    bool helper(int target, vector<int>&arr, int indx) {
        if (target == 0)
            return true;
        
        if (indx == 0)
            return target == arr[indx];
        
        bool take = false;
        bool notTake = false;
        
        if (target >= arr[indx]) {
            take = helper(target - arr[indx], arr, indx - 1);
        }
        
        notTake = helper(target, arr, indx - 1);
        
        return take || notTake;
    }
    // memoization
    bool helper1(int target, vector<int>&arr, int indx, vector<vector<int>>&dp) {
        
        if (target == 0)
            return true;
        
        if (indx == 0)
            return target == arr[indx];
        
        if (dp[indx][target] != -1) {
            return dp[indx][target];
        }
        bool take = false;
        bool notTake = false;
        
        if (target >= arr[indx]) {
            take = helper1(target - arr[indx], arr, indx - 1, dp);
        }
        
        notTake = helper1(target, arr, indx - 1, dp);
        
        return dp[indx][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)
            return false;
        int targetSum = sum / 2;
        
        int n = nums.size();

        // return helper(targetSum, nums, n-1); //1. normal recursion this will give TLE.
        
        //2. memoization
        // vector<vector<int>>dp(n+1, vector<int>(targetSum + 1, -1));
        // return helper1(targetSum, nums, n-1, dp);

        //3. tabulation
        // vector<vector<bool>>dp(n+1, vector<bool>(targetSum + 1, false));
        // for (int i = 0; i < n; i++) {
        //     dp[i][0] = true;
        // }

        // dp[0][nums[0]] = true;

        // for (int indx = 1; indx < n; indx++) {
        //     for (int target = 1; target <= targetSum; target++) {
        //         bool take = false;
        //         bool notTake = false;
                
        //         if (target >= nums[indx]) {
        //             take = dp[indx - 1][target - nums[indx]];
        //         }
                
        //         notTake = dp[indx-1][target];
        //         dp[indx][target] = take || notTake;
        //     }
        // }
        // return dp[n-1][targetSum];

        //4. Space Optimized

        //4. Space Optimization
        vector<bool>curr(targetSum + 1, 0);
        vector<bool> prev(targetSum + 1, 0);
        curr[0] = true;
        if (nums[0] <= targetSum) prev[nums[0]] = true;

        for (int indx = 1; indx < n; indx++) {
            for (int target = 1; target <= targetSum; target++) {
                bool take = false;
                bool notTake = false;
                
                if (target >= nums[indx]) {
                    take = prev[target - nums[indx]];
                }
                
                notTake = prev[target];
                curr[target] = take || notTake;
            }
            prev = curr;
        }
        return prev[targetSum];
    }
};