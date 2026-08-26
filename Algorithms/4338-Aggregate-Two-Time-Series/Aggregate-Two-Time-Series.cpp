class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        
        vector<vector<int>> ans;

        int i = 0, j = 0;
        int n = series1.size();
        int m = series2.size();

        vector<int> timestamps;

        i = 0;
        j = 0;

        while (i < n && j < m) {
            if (series1[i][0] < series2[j][0]) {
                timestamps.push_back(series1[i][0]);
                i++;
            }
            else if (series2[j][0] < series1[i][0]) {
                timestamps.push_back(series2[j][0]);
                j++;
            }
            else {
                timestamps.push_back(series1[i][0]);
                i++;
                j++;
            }
        }

        while (i < n) {
            timestamps.push_back(series1[i][0]);
            i++;
        }

        while (j < m) {
            timestamps.push_back(series2[j][0]);
            j++;
        }

        for (int t : timestamps) {

            int value1 = 0;
            int value2 = 0;

           auto it1 = lower_bound(
                series1.begin(),
                series1.end(),
                vector<int>{t, INT_MIN}
            );

            if (it1 != series1.end()) {
                value1 = (*it1)[1];
            }

            // Find first timestamp >= t in series2
            auto it2 = lower_bound(
                series2.begin(),
                series2.end(),
                vector<int>{t, INT_MIN}
            );

            if (it2 != series2.end()) {
                value2 = (*it2)[1];
            }

            ans.push_back({t, value1 + value2});
        }

        return ans;
    }
};