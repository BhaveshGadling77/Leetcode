class Solution {
public:
    int helper(int r, int c, vector<vector<int>>&tri, vector<vector<int>>&dp) {
        if (r == tri.size() - 1 && c <= tri[r].size()-1) {
            return tri[r][c];
        }
        if (r < 0 || c < 0 || r >= tri.size() || c >= tri[r].size()) {
            return INT_MAX; // out of bound;
        }
        if (dp[r][c] != INT_MIN) {
            return dp[r][c];
        }
        int move = INT_MAX, notmove = INT_MAX;

        if (r + 1 < tri.size() && c + 1 < tri[r+1].size())
            move = tri[r][c] + helper(r+1, c + 1, tri, dp);
        
        if (r + 1 < tri.size())
            notmove = tri[r][c] + helper(r + 1, c, tri, dp);

        return dp[r][c] = min(move, notmove);
    }
    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size();
        

        // return helper(0, 0, tri, dp); //Memoization
        
        //tabulation
        //tip: if memoization is from 0 to n-1 then tabulation is from n-1 to 0
        // vector<vector<int>>dp(n);
        // for (int i = 0; i < n; i++) {
        //     vector<int>temp(tri[i].size(), INT_MIN);
        //     dp[i] = temp;
        // }
        // for (int i = 0; i < tri[n-1].size(); i++) {
        //     dp[n-1][i] = tri[n-1][i];
        // }


        // for (int i = n - 2; i >= 0; i--) {
            
        //     int d = INT_MAX, dg = INT_MAX;
        //     for (int j = i; j >= 0; j--) {

        //         if(i + 1 < n)
        //             d = tri[i][j] + dp[i+1][j];
        //         if (i + 1 < n && j + 1 < tri[i+1].size()) 
        //             dg = tri[i][j] + dp[i+1][j+1];
        //         dp[i][j] = min(d, dg);
        //     }
        // }
        // return dp[0][0];
        
        //Space Optimization
        vector<int>curr(n, INT_MAX);
        vector<int>prev(n, INT_MAX);
        for (int i = 0; i < tri[n-1].size(); i++) {
            prev[i] = tri[n-1][i];
        }
        for (int i = n - 2; i >= 0; i--) {
            
            int d = INT_MAX, dg = INT_MAX;
            for (int j = i; j >= 0; j--) {

                if(i + 1 < n)
                    d = tri[i][j] + prev[j];
                if (i + 1 < n && j + 1 < tri[i+1].size()) 
                    dg = tri[i][j] + prev[j+1];
                curr[j] = min(d, dg);
            }
            prev = curr;
        }
        return prev[0];
    }
};