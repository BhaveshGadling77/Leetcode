class Solution {
public:
    bool check(int r, int c, int n, int m) {
        return r >= 0 && c >= 0 && r < n && c < m;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(); 
        int m = grid[0].size();
        vector<int>dr = {-1, 0, 1, 0};
        vector<int>dc = {0, 1, 0, -1};
        vector<vector<int>> maxHealth(n, vector<int>(m, -1));
        priority_queue<pair<int,pair<int,int>>> pq;
        if (grid[0][0])
            health = health - 1;        
        pq.push({health, {0, 0}});

        while(!pq.empty()) {
            auto it = pq.top();
            int currHealth = it.first;
            auto [r, c] = it.second;
            pq.pop();

            if (currHealth <= maxHealth[r][c])
                continue;
        
            maxHealth[r][c] = currHealth;

            if (currHealth >= 1 && r == n - 1 && c == m - 1) {
                return true;
            }
            else if (r == n - 1 && c == m - 1)
                return false;
            for (int i = 0; i < 4; i++) {
                int nrow = r + dr[i];
                int ncol = c + dc[i];

                if (check(nrow, ncol, n, m)) {
                    if (grid[nrow][ncol])
                        pq.push({currHealth - 1, {nrow, ncol}});
                    else
                        pq.push({currHealth, {nrow, ncol}});
                }
            }
        }
        return false;
    }
};