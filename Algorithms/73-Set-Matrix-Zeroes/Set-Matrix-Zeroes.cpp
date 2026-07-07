class Solution {
public:
    void helper(vector<vector<int>>&mat, int r, int c) {
        for (int i = 0; i < mat.size(); i++) {
            mat[i][c] = 0;
        }

        for (int j = 0; j < mat[0].size(); j++) {
            mat[r][j] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<pair<int,int>>indx;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    indx.push_back({i, j});
                }
            }
        }

        for (auto it: indx) {
            int r = it.first;
            int c = it.second;
            
            helper(matrix, r, c);

        }
    }
};