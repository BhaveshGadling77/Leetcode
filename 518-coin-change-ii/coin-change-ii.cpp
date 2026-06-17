class Solution {
public:
    int helper(int indx, int target, vector<int>&coins, vector<vector<int>>&dp)  {
        if (target == 0)
            return 1; 
        if (indx == 0) {
            return (target % coins[indx] == 0);
        }
        if (dp[indx][target] != -1)
            return dp[indx][target];
         
        int take = 0, notTake = 0;

        notTake = helper(indx-1, target, coins, dp);
        if (target >= coins[indx])
            take = helper(indx, target - coins[indx], coins, dp);
        
        return dp[indx][target] = notTake + take;
    }
    int change(int amount, vector<int>& coins) {
        // vector<vector<int>>dp(coins.size(), vector<int>(amount + 1, 0));
        // return helper(coins.size() - 1, amount, coins, dp);

        //tabulation
        
        vector<vector<unsigned long long>>dp(coins.size() + 1, vector<unsigned long long>(amount + 1, 0));
        //base case
        // for(int T = 0; T <= amount; T++) {
        //     dp[0][T] = (T % coins[0] == 0);
        // }

        // for (int indx = 1; indx < coins.size(); indx++) {
        //     for (int target = 0; target <= amount; target++) {
        //         unsigned long long take = 0, notTake = 0;
        //         notTake = dp[indx - 1][target];
        //         if (target >= coins[indx])
        //             take = dp[indx][target - coins[indx]];
        //         dp[indx][target] = (notTake + take);
        //     }
        // }
        // return dp[coins.size() - 1][amount];
    
        // vector<vector<unsigned long long>>dp(coins.size() + 1, vector<unsigned long long>(amount + 1, 0));
        
        vector<unsigned long long>prev (amount+1, 0), curr(amount + 1, 0);
        //base case
        for(int T = 0; T <= amount; T++) {
            prev[T] = (T % coins[0] == 0);
        }

        for (int indx = 1; indx < coins.size(); indx++) {
            for (int target = 0; target <= amount; target++) {
                unsigned long long take = 0, notTake = 0;
                notTake = prev[target];
                if (target >= coins[indx])
                    take = curr[target - coins[indx]];
                curr[target] = (notTake + take);
            
            }
            prev = curr;
        }
        return prev[amount];
    }
};