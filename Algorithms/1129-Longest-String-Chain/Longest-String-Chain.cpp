class Solution {
public:
    bool compare(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();
        if (n != m + 1) {
            return false;
        }

        int i = 0; //first pointer
        int j = 0; //second pointer

        while(i < n) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        return i == n && j == m;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [&](string s1, string s2) {
            return s1.size() < s2.size();
        });
        vector<int>dp(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++) {

            for (int prev = 0; prev < i; prev++) {
                if (compare(words[i], words[prev]) && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1  + dp[prev];
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
            }
        }

        return maxi;
    }
};