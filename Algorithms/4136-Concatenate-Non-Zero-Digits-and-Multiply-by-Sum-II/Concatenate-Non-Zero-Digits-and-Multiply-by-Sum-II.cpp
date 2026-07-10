class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> prefSum(n);
        int sum = 0;

        vector<int> pos;
        vector<int> digit;

        for (int i = 0; i < n; i++) {
            sum += s[i] - '0';
            prefSum[i] = sum;

            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int k = digit.size();

        vector<long long> prefNum(k + 1, 0);
        vector<long long> pow10(k + 1, 1);

        for (int i = 0; i < k; i++) {
            prefNum[i + 1] = (prefNum[i] * 10 + digit[i]) % MOD;
            pow10[i + 1] = (pow10[i] * 10) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            long long digitSum = prefSum[r] - (l ? prefSum[l - 1] : 0);

            auto itL = lower_bound(pos.begin(), pos.end(), l);
            auto itR = upper_bound(pos.begin(), pos.end(), r);

            if (itL == itR) {
                ans.push_back(0);
                continue;
            }

            int L = itL - pos.begin();
            int R = itR - pos.begin() - 1;

            int len = R - L + 1;

            long long num =
                (prefNum[R + 1] -
                 prefNum[L] * pow10[len] % MOD +
                 MOD) % MOD;

            ans.push_back(num * digitSum % MOD);
        }

        return ans;
    }
};