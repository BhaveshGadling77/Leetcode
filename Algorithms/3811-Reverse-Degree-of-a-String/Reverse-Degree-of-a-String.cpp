class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();

        int val = 26;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (val - (s[i] - 'a')) * (i + 1);
        }

        return ans;
    }
};