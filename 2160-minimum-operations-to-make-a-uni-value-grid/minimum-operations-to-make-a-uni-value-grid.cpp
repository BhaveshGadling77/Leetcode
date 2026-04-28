class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>s;
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        //convert the grid into 1d array 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                s.push_back(grid[i][j]);
            }
        }
        //sort to find the median of elements.
        sort(s.begin(), s.end());
        int med = s[s.size() / 2];
        //traverse the 1d array and get the count of ops by diff / x;
        for (int i = 0; i < m * n; i++) {
            int diff = abs(s[i] - med);
            if (diff % x != 0)
                return -1;
            cnt += diff / x;
        }
        return cnt;
    }
};