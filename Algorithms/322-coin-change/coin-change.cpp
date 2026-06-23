class Solution {
public:
    int helper(int amount, int indx, vector<int>&coins, vector<vector<int>>&dp) {
        // indx == 0
        if (indx == 0) {
            if (amount % coins[indx] == 0) {
                return amount / coins[indx];
            } else {
                return 1e8;
            }
        }
        if (dp[indx][amount] != 1e8) {
            return dp[indx][amount];
        }
        int take = INT_MAX, notTake = INT_MAX;
        
        if (coins[indx] <= amount)
            take = 1 + helper(amount - coins[indx], indx, coins, dp);
        
        notTake = helper(amount, indx - 1, coins, dp);
        
        return dp[indx][amount] = min(notTake, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>>dp(coins.size(), vector<int>(amount + 1, 1e8));
        // // int res = helper(amount, coins.size() - 1, coins, dp);
        
        // //tabulation
        // for (int i = 0; i <= amount; i++) {
        //     if (i % coins[0] == 0) {
        //         dp[0][i] = i / coins[0];
        //     } else {
        //         dp[0][i] = 1e8;
        //     }
        // }

        // for (int indx = 1; indx < coins.size(); indx++) {
        //     for (int target = 0; target <= amount; target++) {
        //         int take = 1e8, notTake = 1e8;
        
        //         if (coins[indx] <= target)
        //             take = 1 + dp[indx][target - coins[indx]];
                
        //         notTake = dp[indx - 1][target];
                
        //         dp[indx][target] = min(notTake, take);
        //     }
        // }

        // return dp[n-1][amount] == 1e8 ? -1 : dp[n-1][amount];
        
        //space optimization
        
        vector<int>curr(amount + 1, 0);
        vector<int>prev(amount + 1, 0);
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) {
                prev[i] = i / coins[0];
            } else {
                prev[i] = 1e8;
            }
        }
        
        for (int indx = 1; indx < coins.size(); indx++) {
            for (int target = 0; target <= amount; target++) {
                int take = 1e8, notTake = 1e8;
        
                if (coins[indx] <= target)
                    take = 1 + curr[target - coins[indx]];
                
                notTake = prev[target];
                
                curr[target] = min(notTake, take);
            }
            prev = curr;
        }

        return prev[amount] == 1e8 ? -1 : prev[amount];
    }
};