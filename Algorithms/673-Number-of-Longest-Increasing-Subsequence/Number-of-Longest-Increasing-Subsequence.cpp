class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp1(n, 1), cnt(n, 1);
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] > nums[prev] && 1 + dp1[prev] > dp1[i]) {
                    dp1[i] = 1  + dp1[prev];
                    cnt[i] = cnt[prev];
                } else if (nums[i] > nums[prev] && 1 + dp1[prev] == dp1[i]) {
                    cnt[i] += cnt[prev];
                }
            }
            maxi = max(maxi, dp1[i]);
        }
        int nos = 0;
        for (int i = 0; i < n; i++) {
            if (dp1[i] == maxi) {
                nos += cnt[i];
            }
        }
        return nos;
    }
};