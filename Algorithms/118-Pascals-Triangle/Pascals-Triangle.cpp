class Solution {
public:
    vector<int>generateRow(int row) {
        vector<int>ans;
        int res = 1;
        ans.push_back(1);
        for (int col = 1; col < row; col++) {
                res = res * (row - col);
                res = res / col;
                ans.push_back(res);
        }

        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        
        for (int i = 1; i <= numRows; i++) {
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};