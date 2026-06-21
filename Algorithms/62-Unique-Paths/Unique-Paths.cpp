class Solution {
public:
    
    int helper(int r, int c, int m, int n, vector<vector<int>>&dp) {
        if (r == m-1 && c == n - 1) {
            return 1;
        }
        if (r >= m || c >= n) {
            return 0;
        }
        if (dp[r][c] != -1) {
            return dp[r][c];
        }
        int down = helper(r + 1, c, m, n, dp);
        int right = helper(r, c + 1, m, n, dp);
        return dp[r][c] = down + right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        
        dp[m-1][n-1] = 1;
        int down = 0, right = 0;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                down = 0, right = 0;
                if (i == m-1 && j == n-1) {
                    dp[m-1][n-1] = 1;
                } else {
                    if (i + 1 < m) down = dp[i+1][j];
                    if (j + 1 < n) right = dp[i][j+1];
                    dp[i][j] = down + right;
                }
            }
        }
        return dp[0][0];
    }
};