class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();

        //generate all subarrays this is brute force it can be optimized further
        int reqRatio = (double)a / (double)b;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int x = 0;
            int y = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0) {
                    x++;
                } else {
                    y++;
                }

                if (y > 0 && b * x <= a * y) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};