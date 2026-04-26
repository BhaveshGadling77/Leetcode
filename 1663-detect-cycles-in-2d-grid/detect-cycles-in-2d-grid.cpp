class Solution {
public:
    bool check(int r, int c, int n, int m) {
        return r >= 0 && c >= 0 && r < n && c < m;
    }   
    bool dfs(vector<vector<char>>& grid, int r, int c, int pr, int pc, vector<vector<int>>& vis) {
        vis[r][c] = 1;
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        for (auto d : dir) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (check(nr, nc, grid.size(), grid[0].size()) && grid[nr][nc] == grid[r][c]) {
                
                if (!vis[nr][nc]) {
                    if (dfs(grid, nr, nc, r, c, vis))
                        return true;
                }
                else if (nr != pr || nc != pc) {
                    // visited and not parent -> cycle
                    return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m));
        //approach is simple visit the nodes using dfs, if the node 
        //found visited and is not parent then this is a cycle.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m ; j++) {
                if (!vis[i][j])
                    if (dfs(grid, i, j, -1, -1, vis))
                        return true;

            }
        }
        return false;
    }
};