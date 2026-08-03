class Solution {
public:
    int helper(int indx, bool isAlice, vector<int>&stones, vector<vector<int>>&dp) {
        if (indx == stones.size())
            return 0;
        
        if (dp[indx][isAlice] != -1)
            return dp[indx][isAlice];
        
        int n = stones.size();

        if (isAlice) {
            int maxi = INT_MIN;
            int sumTaken = 0;
            for (int i = indx; i < min(indx + 3, n); i++) {
                sumTaken += stones[i];
                maxi = max(maxi, sumTaken - helper(i + 1, false, stones, dp));
            }
            return dp[indx][isAlice] = maxi;
        } else {
            int maxi = INT_MIN;
            int sumTaken = 0;
            for (int i = indx; i < min(indx + 3, n); i++) {
                sumTaken += stones[i];
                maxi = max(maxi, sumTaken - helper(i + 1, true, stones, dp));
            }
            return dp[indx][isAlice] = maxi;
        }
    }
    string stoneGameIII(vector<int>& stones) {

        vector<vector<int>>dp(stones.size() + 1, vector<int>(2, -1));
        int res = helper(0, true, stones, dp);
        if (res == 0) {
            return "Tie";
        } else if (res > 0) {
            return "Alice";
        } else {
            return "Bob";
        }
    }
};