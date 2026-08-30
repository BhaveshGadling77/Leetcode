class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIndx = 0;
        int maxIndx = 0;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        // find min and max index;
        for (int i = 0; i < n; i++) {
            if (mini > nums[i]) {
                mini = nums[i];
                minIndx = i;
            }
            if (maxi < nums[i]) {
                maxi = nums[i];
                maxIndx = i;
            }
        }
        int ans = 0;
        if (minIndx <= n / 2 && maxIndx <= n / 2) {
            ans = max(minIndx + 1, maxIndx + 1);
        } else if (minIndx < n / 2 && maxIndx > n / 2) {
            ans = min({minIndx + 1 + (n - maxIndx),
                        maxIndx + 1,
                        n - minIndx}) ;
        } else if (minIndx > n / 2 && maxIndx < n / 2) {
            ans = min({maxIndx + 1 + (n - minIndx),
                        minIndx + 1, 
                        n - maxIndx});
        } else {
            minIndx = n - minIndx;
            maxIndx = n - maxIndx;
            ans = max(minIndx, maxIndx);
        }
        return ans;
    }
};