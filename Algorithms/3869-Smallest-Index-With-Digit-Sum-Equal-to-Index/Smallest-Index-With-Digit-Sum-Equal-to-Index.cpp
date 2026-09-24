class Solution {
public:
    int sumOfDigits(int n) {
        int cnt = 0;

        while (n > 0) {
            cnt += n % 10;
            n = n / 10;
        }

        return cnt;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int res = sumOfDigits(nums[i]);
            if (res == i) {
                return i;
            }
        }

        return -1;
    }
};