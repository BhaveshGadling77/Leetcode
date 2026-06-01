class Solution {
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] || grid[n-1][n-1])
            return -1;
        //reason why used queue instead of priority queue.
        //if i am using the 
        vector<vector<int>>dist(n, vector<int>(n, INT_MAX));
        vector<int>dr = {-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int>dc = {-1, 0, 1, 1, 1, 0, -1, -1};
        queue<vector<int>>q;
        q.push({1, 0, 0}); //dist, row, col

        dist[0][0] = 1 ;

        while(!q.empty()) {
            auto it = q.front();
            int row = it[1];
            int col = it[2];
            int dis = it[0];

            q.pop();
            //for every 8 directions
            for (int i = 0; i < 8; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                //if the new row and new col is valid then check !grid[nrow][ncol] should be true 

                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < n && !grid[nrow][ncol]) {
                    if (dis + 1 < dist[nrow][ncol]) {
                        q.push({dis +1, nrow, ncol});
                        dist[nrow][ncol] = dis + 1;
                    }
                }
                if (dist[n-1][n-1] != INT_MAX)
                    return dist[n-1][n-1];
            }
        }
        return dist[n-1][n-1] == INT_MAX ? -1 : dist[n-1][n-1];
    }
};