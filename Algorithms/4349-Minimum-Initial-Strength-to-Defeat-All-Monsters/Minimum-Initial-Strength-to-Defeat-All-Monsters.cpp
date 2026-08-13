class Solution {
public:
    bool canDefeat(long long initial, vector<int>& monsters, vector<long long>& bonus) {
        long long curr = initial;

        for (int i = 0; i < monsters.size(); i++) {
            if (curr + bonus[i] < monsters[i])
                return false;

            curr = max(0LL, curr - (long long)monsters[i]);
        }

        return true;
    }

    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();

        // array to calculate bonuses
        vector<long long> diff(n + 1, 0);

        for (auto &b : boosts) {
            int l = b[0];
            int r = b[1];
            int v = b[2];

            diff[l] += v;
            if (r + 1 < n)
                diff[r + 1] -= v;
        }

        vector<long long> bonus(n);
        bonus[0] = diff[0];
        for (int i = 1; i < n; i++)
            bonus[i] = bonus[i - 1] + diff[i];

        long long low = 0;
        long long high = 0;

        for (int x : monsters)
            high += x;

        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (canDefeat(mid, monsters, bonus)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};