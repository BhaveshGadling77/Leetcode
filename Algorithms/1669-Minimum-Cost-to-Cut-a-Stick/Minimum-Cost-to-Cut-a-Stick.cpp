class Solution {
public:
    // int helper(int i, int j, vector<int>&cuts) {
    //     if (i > j)
    //         return 0;
        
    //     long long mini = INT_MAX;
    //     for (int ind = i; ind <= j; ind++) {
    //         long long cost = cuts[j+1] - cuts[i-1] 
    //                     + helper(i, ind-1, cuts)
    //                     + helper(ind + 1, j, cuts);
    //         mini = min(mini, cost);
    //     }
    //     return mini;
    // }

    int helper(int i, int j, vector<int>&cuts, vector<vector<int>>&dp) {
        if (i > j)
            return 0;
        
        if (dp[i][j] != INT_MAX)
            return dp[i][j];
        long long mini = INT_MAX;
        for (int ind = i; ind <= j; ind++) {
            long long cost = cuts[j+1] - cuts[i-1] 
                        + helper(i, ind-1, cuts, dp)
                        + helper(ind + 1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        // return helper(1, cuts.size() -2, cuts); //recursion
        
        //memoization
        int c = cuts.size();
        vector<vector<int>>dp(c-1, vector<int>(c-1 , INT_MAX));
        return helper(1, cuts.size() - 2, cuts, dp);
    }
};