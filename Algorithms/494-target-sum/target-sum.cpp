class Solution {
private:
    int helper(vector<int>&arr, int k, int indx, vector<vector<int>>&dp) {
        if (indx == 0) {
            if (k == 0) {
                if (arr[indx] == 0) return 2;
                else return 1;
            } else {
                return (arr[indx] == k);
            }
        }
        if (dp[indx][k] != -1)
            return dp[indx][k];
        
        int take = 0;

        if(arr[indx] <= k) take = helper(arr, k - arr[indx], indx - 1, dp);
        int notTake = helper(arr, k, indx - 1, dp);
        return dp[indx][k] = (take + notTake);
    }

    int findWays(vector<int>& arr, int k)
    {	
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(k + 1, -1));
        return helper(arr, k, arr.size() - 1, dp);
    }

    int countPartitions(int n, int d, vector<int> &arr) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0) - d;
        if (totalSum % 2 == 1 || totalSum < 0)
            return 0;
        
        return findWays(arr, totalSum / 2);
    }


public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(), target, nums);
    }
};