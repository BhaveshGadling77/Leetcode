class Solution {
public:
    int dp[101][101];
    int suffix[101];
    int n;

    int helper(int idx, int M, vector<int>& piles) {

        if (idx >= n)
            return 0;

        // Can take all remaining piles
        if (idx + 2 * M >= n)
            return suffix[idx];

        if (dp[idx][M] != -1)
            return dp[idx][M];

        int ans = 0;

        for (int X = 1; X <= 2 * M; X++) {
            ans = max(ans,
                      suffix[idx] -
                      helper(idx + X, max(M, X), piles));
        }

        return dp[idx][M] = ans;
    }


    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        memset(dp, -1, sizeof(dp));

        suffix[n] = 0;
        for (int i = n - 1; i >= 0; i--)
            suffix[i] = suffix[i + 1] + piles[i];

        return helper(0, 1, piles);
    }
};