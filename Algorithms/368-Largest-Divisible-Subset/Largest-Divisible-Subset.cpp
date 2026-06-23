class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        //same LIS code just shuttle change 
        sort(nums.begin(), nums.end());
        vector<int>dp(n, 1), hash(n);
        int lastIndx = 0;
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i]) { // nums[i] > nums[prev] --> nums[i] % nums[prev];
                    dp[i] = 1  + dp[prev];
                    hash[i] = prev;
                }
            }
            if (dp[i] > maxi) {

                maxi = dp[i];
                lastIndx = i;
            }
        }
        vector<int>temp;
        temp.push_back(nums[lastIndx]);
        while (hash[lastIndx] != lastIndx) {
            lastIndx = hash[lastIndx];
            
            temp.push_back(nums[lastIndx]);
        }
        

        for (auto it: temp)
            cout << it << " ";
        return temp;
    }
};