class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mpp;
        int l = 0;
        int r = 0;
        int maxi = 0;
        while (l < n && r < n) {
            mpp[nums[r]]++;

            if (mpp[nums[r]] > k) {
                int temp = nums[r];
                while (l < r && mpp[temp] > k) {
                    mpp[nums[l]]--;
                    l++;
                }
                mpp[nums[r]]--;
            } else {

            maxi = max(r - l + 1, maxi);
            r++;
            }
        }
        return maxi;
    }
};