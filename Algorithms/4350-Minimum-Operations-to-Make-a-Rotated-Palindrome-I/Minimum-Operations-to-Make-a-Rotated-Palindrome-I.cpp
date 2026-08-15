class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int l = 0;
            int r = n - 1;
            int cnt = i;
            while (l < r) {
                if (s[l] == s[r]) {
                    l++;
                    r--;
                    continue;
                }
                int ops = abs(s[l] - s[r]);

                cnt += min(ops, 26-ops);
                l++;
                r--;
            }
            ans = min(ans, cnt);
            rotate(s.begin(), s.begin() + 1, s.end());
        }
        
        return ans;
    }
};