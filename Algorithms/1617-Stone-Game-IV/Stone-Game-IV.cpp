class Solution {
public:
    
    bool helper(int n, vector<int>&dp) {
        if (n < 0)
            return false;
        
        if (n == 0) {
            return false;
        }
        if (n == 1)
            return true;
        if (dp[n] != -1) 
            return dp[n];
        for (int i = 1; i * i <= n; i++) {
            int p = pow(i, 2);
            dp[n - p] = helper(n - pow(i, 2), dp);
            if (dp[n-p] == false)
                return true;
        }
        return dp[n] = false;
    }
    bool winnerSquareGame(int n) {
        vector<int>dp(n + 1, -1);
        return helper(n, dp);
    }
};