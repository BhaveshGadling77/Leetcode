class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& itv) {
        int n = itv.size();
        sort(itv.begin(), itv.end(), [&](vector<int>&a, vector<int>&b) {

            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });

        int ans = 0;
        int maxEnd = 0;

        for (auto &x : itv) {
            if (x[1] > maxEnd) {
                ans++;
                maxEnd = x[1];
            }
        }

        return ans;
    }
};