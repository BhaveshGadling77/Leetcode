class Solution {
public:
    void dfs(long long num, int low, int high, vector<int>& ans) {
        if (num > high)
            return;

        if (num >= low)
            ans.push_back(num);

        int lastDigit = num % 10;

        // Can't extend beyond 9
        if (lastDigit == 9)
            return;

        long long nextNum = num * 10 + (lastDigit + 1);

        dfs(nextNum, low, high, ans);
    }

    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        // start from every possible first digit
        for (int i = 1; i <= 9; i++) {
            dfs(i, low, high, ans);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};