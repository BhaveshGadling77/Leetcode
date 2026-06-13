class Solution {
public:
    // 1. Naive Recursion
    // int helper(vector<vector<int>>&grid, int r, int c, int n, int m) {
    //     if (r == n - 1 && c == m - 1) {
    //         return grid[r][c];
    //     }
    //     if (r >= n || c >= m || c < 0 || r < 0) {
    //         return INT_MAX; //path not found
    //     }
    //     int down = INT_MAX, right = INT_MAX;
    //     if (c + 1 < m) right = grid[r][c] + helper(grid, r, c+1, n, m);
    //     if (r + 1 < n) down = grid[r][c] + helper(grid, r + 1, c, n, m);

    //     return min(right, down);
    // }
    
    // 2. memoization

    int helper(vector<vector<int>>&grid, int r, int c, int n, int m, vector<vector<int>>&dp) {
        if (r == n - 1 && c == m - 1) {
            return grid[r][c];
        }
        if (r >= n || c >= m || c < 0 || r < 0) {
            return INT_MAX;
        }
        
        if (dp[r][c] != -1) {
            return dp[r][c];
        }

        int down = INT_MAX, right = INT_MAX;
        if (c + 1 < m) right = grid[r][c] + helper(grid, r, c + 1, n, m, dp);
        if (r + 1 < n) down = grid[r][c] + helper(grid, r + 1, c, n, m, dp);

        return dp[r][c] = min(right, down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        // return helper(grid, 0, 0, n, m, dp);
        

        //3. tabulation
        // dp[0][0] = grid[0][0];
        
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         int up = INT_MAX, left = INT_MAX;
        //         if (i == 0 && j == 0) {
        //             dp[i][j] = grid[0][0];
        //         } else {
        //             if (i > 0) up = grid[i][j] + dp[i-1][j];
        //             if (j > 0) left = grid[i][j] + dp[i][j-1];
        //             dp[i][j] = min(up, left);
        //         }
        //     }
        // }
        // return dp[n-1][m-1];
    
        //4. Memory Optimization
        dp[0][0] = grid[0][0];
        vector<int>curr(m, -1);
        vector<int>prev(m, -1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = INT_MAX, left = INT_MAX;
                if (i == 0 && j == 0) {
                    curr[j] = grid[0][0];
                } else {
                    if (i > 0) up = grid[i][j] + prev[j];
                    if (j > 0) left = grid[i][j] + curr[j-1];
                    curr[j] = min(up, left);
                }
            }
            prev = curr;
        }
        return prev[m-1];
    }
};