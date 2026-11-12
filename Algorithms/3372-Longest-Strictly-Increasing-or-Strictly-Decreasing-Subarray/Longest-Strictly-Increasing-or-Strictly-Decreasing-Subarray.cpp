class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        //constraints are short so brute force will work

        //strictly increasing
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j-1] >= nums[j])
                    break;
                maxi = max(maxi, j - i + 1);
            }
        }
        

        //strictly decreasing
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j-1] <= nums[j])
                    break;
                maxi = max(maxi, j - i + 1);
            }
        }
        maxi = max(maxi, 1);
        return maxi;
    }
};