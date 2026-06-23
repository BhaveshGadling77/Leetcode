class Solution {
public:
    int f(int r, int c, int n, int m, vector<vector<int>>&grid, vector<vector<int>>&dp) {
        if (r == n-1 && c == m-1) {
            return 1;
        }
        if (r >= n || c >= m) {
            return 0;
        }

        if (r >= 0 && c >= 0 && grid[r][c] == 1) {
            return 0;
        }
        
        if (dp[r][c] != -1) {
            return dp[r][c];
        }
        int right = 0, down = 0;
        right = f(r+1, c, n, m, grid, dp);
        down = f(r, c+1, n, m, grid, dp); 
        return dp[r][c] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        // dp[0][0] = 0;
        int res = f(0, 0, n, m, grid, dp);
        return grid[n-1][m-1] == 1 ? 0 : res;
    }
};