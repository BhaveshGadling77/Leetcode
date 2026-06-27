class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int cnt = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        //tabulation because the recursive solution is not that intuitive.
        vector<vector<int>>dp(m, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i];
            cnt += dp[0][i];
        }

        for (int i = 1; i < m; i++) {
            dp[i][0] = matrix[i][0];
            cnt += dp[i][0];
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]}); 
                    cnt += dp[i][j];
                }
            }
        }
        return cnt;

    }
};