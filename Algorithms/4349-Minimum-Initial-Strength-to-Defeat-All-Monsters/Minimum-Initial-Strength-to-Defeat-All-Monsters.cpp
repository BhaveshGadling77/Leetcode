class Solution {
public:
    bool helper(long long st, vector<long long>&bonus, vector<int>&mons) {
        int n = mons.size();
        for (int i = 0; i < n; i++) {
            if ((long long)(st + bonus[i]) >= (long long)mons[i]) {
                st = max(st - mons[i], 0LL);
            } else {
                return false;
            }
        }

        return true;
    }
    long long minInitialStrength(vector<int>& mons, vector<vector<int>>& boosts) {
        int n = mons.size();
        int m = boosts.size();
        vector<long long>bonus(n);
        vector<long long>diff(n);
        vector<long long>temp(mons.begin(), mons.end());
        // build the bonus array
        for (auto &p: boosts) {
            int l = p[0];
            int r = p[1];
            int v = p[2];
            
            if (l < n)
                diff[l] += v;
            if (r + 1 < n)
                diff[r + 1] += -1 * v;
        }
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += diff[i];
            bonus[i] = sum;
        }

        // search for the appropriate value of starting strength
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            sum += temp[i];
        }
        long long low = 0;
        long long high = sum;
        while (low <= high) {
            
            long long mid = low + (high - low) / 2LL;

            if (helper(mid, bonus, mons)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } 
        return low;
    }
};