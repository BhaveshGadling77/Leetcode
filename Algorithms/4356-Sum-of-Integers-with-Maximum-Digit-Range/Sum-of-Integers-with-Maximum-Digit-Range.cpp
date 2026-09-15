class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int temp = nums[i];
            int maxiDigit = INT_MIN;
            int miniDigit = INT_MAX;
            while (temp > 0) {
                int digit = temp % 10;
                temp = temp / 10;

                maxiDigit = max(maxiDigit, digit);
                miniDigit = min(miniDigit, digit);
            }
            maxi = max(maxi, maxiDigit - miniDigit);
        }
        for (int i = 0; i < n; i++) {
            int temp = nums[i];
            int maxiDigit = INT_MIN;
            int miniDigit = INT_MAX;
            while (temp > 0) {
                int digit = temp % 10;
                temp = temp / 10;

                maxiDigit = max(maxiDigit, digit);
                miniDigit = min(miniDigit, digit);
            }
            if (maxiDigit - miniDigit == maxi) {
                ans += nums[i];
            }
        }
        return ans;

    }
};