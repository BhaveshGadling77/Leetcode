class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        //construct prefixGCD
        vector<int>prefixGcd;
        int maxi = nums[0];
        for (int i = 0; i < n; i++) {
            maxi = max(nums[i], maxi);
            prefixGcd.push_back(gcd(nums[i], maxi));
            // cout << prefixGcd[i] << " ";
        }
        // cout << endl;
        long long ans = 0;
        sort(prefixGcd.begin(), prefixGcd.end());
        priority_queue<int>maxH;
        priority_queue<int, vector<int>, greater<int>>minH;
        for (int i = 0; i < n / 2; i++) {
            // cout << prefixGcd[i] << endl;
            minH.push(prefixGcd[i]);
        }
        for (int i = n-1; i >= n / 2; i--) {
            // cout << prefixGcd[i] << endl;
            maxH.push(prefixGcd[i]);
        }

        while (!minH.empty() && !maxH.empty()) {
            int currMin = minH.top();
            int currMax = maxH.top();
            cout << currMin << " " << currMax << endl;
            ans += gcd(currMin, currMax);
            minH.pop();
            maxH.pop();
        }
        return ans;
    }
};