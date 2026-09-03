class Solution {
public:
    int countValidPrefixes(string s) {
        int cnt0 = 0;
        int cnt1 = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0')
                cnt0++;
            else
                cnt1++;

            if (abs(cnt0 - cnt1) <= 1)
                ans++;
        }

        return ans;
    }
};