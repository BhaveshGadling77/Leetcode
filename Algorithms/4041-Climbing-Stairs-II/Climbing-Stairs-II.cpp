class Solution {
public:
    //Normal Recursive solution
    // int helper(int i, vector<int>&costs) {
    //     if (i >= costs.size())
    //         return 0;
        
    //     int cost1 = INT_MAX, cost2 = INT_MAX, cost3 = INT_MAX;

    //     // for i + 1
    //     if (i + 1 <= costs.size()) {
    //         cost1 = costs[i] + 1 + helper(i + 1, costs);
    //     }

    //     // for i + 2
    //     if (i + 2 <= costs.size())
    //         cost2 = costs[i + 1] + 4 + helper(i + 2, costs);
        
    //     // for i + 3
    //     if (i + 3 <= costs.size())
    //         cost3 = costs[i + 2] + 9 + helper(i + 3, costs);

    //     return min({cost1, cost2, cost3});
    // }
    
    // Memoization approach
    int helper(int i, vector<int>&costs, vector<int>&dp) {
        if (i >= costs.size())
            return 0;
        
        if (dp[i] != -1)
            return dp[i];
        
        int cost1 = INT_MAX, cost2 = INT_MAX, cost3 = INT_MAX;

        // for i + 1
        if (i + 1 <= costs.size()) {
            cost1 = costs[i] + 1 + helper(i + 1, costs, dp);
        }

        // for i + 2
        if (i + 2 <= costs.size())
            cost2 = costs[i + 1] + 4 + helper(i + 2, costs, dp);
        
        // for i + 3
        if (i + 3 <= costs.size())
            cost3 = costs[i + 2] + 9 + helper(i + 3, costs, dp);

        return dp[i] = min({cost1, cost2, cost3});
    }


    int climbStairs(int n, vector<int>& costs) {
        // vector<int>dp(n, -1);
        // return helper(0, costs, dp); // as this is also giving TLE let's try the tabulation.

        //tabulation
        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;

        for (int i = 1; i <= n; i++) {

            // for i-1
            dp[i] = min(dp[i], dp[i - 1] + costs[i - 1] + 1);

            // for i-2
            if (i >= 2)
                dp[i] = min(dp[i], dp[i - 2] + costs[i - 1] + 4);

            // for i-3
            if (i >= 3)
                dp[i] = min(dp[i], dp[i - 3] + costs[i - 1] + 9);
        }

        return dp[n];
    }
};