class Solution {
private:
    int helper(int r, int c, vector<vector<int>>&mat, vector<vector<int>>&dp) {
        if (r < 0 || r >= mat.size() || c < 0 || c >= mat[0].size()) {
            return INT_MAX; // out of bound;
        }
        
        if (r == 0 && c < mat[0].size()) {
            return mat[r][c];
        }

        if (dp[r][c] != -1) {
            return dp[r][c];
        }
        int up = INT_MAX, leftDg = INT_MAX, rightDg = INT_MAX;
        
        up = mat[r][c] + helper(r - 1, c, mat, dp);
        if (c - 1 < mat[0].size() && c - 1 >= 0) 
            leftDg = mat[r][c] + helper(r - 1, c -1, mat, dp);
        if (c + 1 < mat[0].size() && c + 1 >= 0) 
            rightDg = mat[r][c] + helper(r - 1, c + 1, mat, dp);

        return dp[r][c] = min({up, leftDg, rightDg});
    }

public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int maxi = INT_MAX;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        
        for (int i = 0; i < m; i++) {
            dp[0][i] = mat[0][i];
        }
        // Memoization
        // for (int i = 0; i < m; i++) {
        //     maxi = max(maxi, helper(n-1, i, matrix, dp));
        // }

        // Tabulation
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = INT_MAX, leftDg = INT_MAX, rightDg = INT_MAX;
                up = mat[i][j] + dp[i-1][j];
                if (j - 1 >= 0) leftDg = mat[i][j] + dp[i-1][j-1];
                if (j + 1 < mat[0].size()) rightDg = mat[i][j] + dp[i - 1][j + 1];

                dp[i][j] = min({up, leftDg, rightDg});
            }
        }
        maxi = dp[n-1][0];
        
        for (int j = 1; j < m; j++) {
            maxi = min(dp[n-1][j], maxi);
        }
        
        return maxi;
    }
};