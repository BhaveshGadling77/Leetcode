class Solution {
public:
    void helper(vector<vector<int>>& grid, int k, int layer, int n, int m) {

        vector<int> temp;

        int top = layer;
        int left = layer;
        int bottom = n - layer - 1;
        int right = m - layer - 1;

        // top row
        for (int j = left; j <= right; j++) {
            temp.push_back(grid[top][j]);
        }

        // right column
        for (int i = top + 1; i <= bottom; i++) {
            temp.push_back(grid[i][right]);
        }

        // bottom row
        for (int j = right - 1; j >= left; j--) {
            temp.push_back(grid[bottom][j]);
        }

        // left column
        for (int i = bottom - 1; i > top; i--) {
            temp.push_back(grid[i][left]);
        }

        // rotate
        int sz = temp.size();
        k %= sz;

        vector<int> rotated(sz);

        for (int i = 0; i < sz; i++) {
            rotated[i] = temp[(i + k) % sz];
        }

        int idx = 0;

        // put back top row
        for (int j = left; j <= right; j++) {
            grid[top][j] = rotated[idx++];
        }

        // put back right column
        for (int i = top + 1; i <= bottom; i++) {
            grid[i][right] = rotated[idx++];
        }

        // put back bottom row
        for (int j = right - 1; j >= left; j--) {
            grid[bottom][j] = rotated[idx++];
        }

        // put back left column
        for (int i = bottom - 1; i > top; i--) {
            grid[i][left] = rotated[idx++];
        }
    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        // function to traverse one layer.
        int layers = min(n, m) / 2;
        for (int i = 0; i < layers; i++) {
            //helper will do all the job of rotating array. 
            helper(grid, k , i, n, m);
        }
        return grid;
    }
};