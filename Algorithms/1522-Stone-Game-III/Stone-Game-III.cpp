class Solution {
public:
    int helper(int indx, vector<int>&stones, vector<int>&dp) {
        if (indx == stones.size())
            return 0;
        
        if (dp[indx] != -1)
            return dp[indx];
        
        int n = stones.size();
        int stonesTaken = 0;
        int maxi = INT_MIN;
        for (int i = indx; i < min(indx + 3, n); i++) {
            stonesTaken += stones[i];
            maxi = max(maxi, stonesTaken - helper(i + 1, stones, dp));
        }
        
        return dp[indx] = maxi;
        
    }
    string stoneGameIII(vector<int>& stones) {

        vector<int>dp(stones.size() + 1, -1);
        int res = helper(0, stones, dp);
        if (res == 0) {
            return "Tie";
        } else if (res > 0) {
            return "Alice";
        } else {
            return "Bob";
        }
    }
};