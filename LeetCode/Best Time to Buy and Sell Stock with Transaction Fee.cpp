class Solution {
public:
    int helper(int indx, int buy, vector<int>&prices, vector<vector<int>>&dp) {
        if (indx >= prices.size())
            return 0;
        
        if (dp[indx][buy] != -1)
            return dp[indx][buy];
        int profit = INT_MIN;
        if (buy) { // buy
            int take = -prices[indx] + helper(indx + 1, 0, prices, dp);
            int notTake = helper(indx + 1, 1, prices, dp);
            profit = max(take, notTake);
        } else {// sell 
            int take = prices[indx] + helper(indx + 2, 1, prices, dp);
            int notTake = helper(indx + 1, 0, prices, dp);
            profit = max(take, notTake);
        }
        return dp[indx][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        // vector<vector<int>>dp(prices.size(), vector<int>(2, -1));

        // return helper(0, 1, prices, dp);
        // 1 -> can buy 0 -> cannot buy. 
        int n = prices.size();
        vector<vector<int>>dp(n + 2, vector<int>(2, 0));

        //tabulation
        for (int indx = n - 1; indx >= 0; indx--) {    
                
            dp[indx][1] = max(-prices[indx] + dp[indx + 1][0], dp[indx + 1][1]);
                
            dp[indx][0] = max(prices[indx] + dp[indx + 1][1] - fee, dp[indx + 1][0]);
        }
        return dp[0][1];
    }
};