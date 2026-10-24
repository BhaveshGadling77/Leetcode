class Solution {
public:
    vector<int>lastStepcoord(int r, int c, char lastStep) {
        if (lastStep == 'L') {
            return {r, c + 1};
        } else if (lastStep == 'R') {
            return {r, c - 1};
        } else if (lastStep == 'U') {
            return {r + 1, c};
        } else {
            return {r - 1, c};
        }
    }
    vector<int> helper(int r, int c, char lastStep, vector<vector<int>>&vis, vector<vector<char>>&grid) {
        
        if (r < 0 || c < 0 ||  r >= grid.size() || c >= grid[0].size()) {
            return lastStepcoord(r, c, lastStep);
        }

        if (vis[r][c]) {
            return lastStepcoord(r,c,lastStep);
        }
        vis[r][c] = 1;

        if (grid[r][c] == 'L') {
            return helper(r, c - 1, grid[r][c], vis, grid);
        } else if (grid[r][c] == 'R') {
            return helper(r, c + 1, grid[r][c], vis, grid);
        } else if (grid[r][c] == 'U') {
            return helper(r - 1, c, grid[r][c], vis, grid);
        } else {
            return helper(r + 1, c, grid[r][c], vis, grid);
        }
    }
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m));
        
        return helper(0, 0, grid[0][0], vis, grid);
    }
};