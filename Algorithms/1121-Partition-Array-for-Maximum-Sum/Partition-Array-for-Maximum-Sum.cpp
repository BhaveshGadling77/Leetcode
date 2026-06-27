class Solution {
public:
    // Recursion
    // int helper(int indx, int k, vector<int>&arr) {
    //     if (indx == arr.size())
    //         return 0;
    //     int maxi = INT_MIN, len = 0, maxsum = 0;
    //     int n = arr.size();
    //     for (int i = indx; i < min(n, indx + k); i++) {
    //         len++;
    //         maxi = max(maxi, arr[i]);
    //         int sum = len * maxi + helper(i + 1, k, arr);
    //         maxsum = max(maxsum, sum);
    //     }
    //     return maxsum;
    // }

    // memoization
    int helper(int indx, int k, vector<int>&arr, vector<int>& dp) {
        if (indx == arr.size())
            return 0;

        if (dp[indx] != -1)
            return dp[indx];
        
        int maxi = INT_MIN, len = 0, maxsum = 0;
        int n = arr.size();
        for (int i = indx; i < min(n, indx + k); i++) {
            len++;
            maxi = max(maxi, arr[i]);
            int sum = len * maxi + helper(i + 1, k, arr, dp);
            maxsum = max(maxsum, sum);
        }
        return dp[indx] = maxsum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        // return helper(0, k, arr);


        //memoization
        vector<int>dp(n, -1);
        return helper(0, k, arr, dp);
    }
};