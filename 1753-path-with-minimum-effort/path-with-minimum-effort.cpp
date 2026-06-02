class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();
        if (n == m && n == 1)
            return 0;
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, 
            greater<pair<int,pair<int,int>>>>pq;
        
        vector<vector<int>>del = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        while(!pq.empty()) { 
            auto it = pq.top();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            if (row == n-1 && col == m-1) {
                return diff;
            }
            pq.pop();
            for (auto dir: del) {
                int nrow = row + dir[0];
                int ncol = col + dir[1];
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m ) {
                    int newEffort = max(abs(h[row][col] - h[nrow][ncol]), diff);
                    if (newEffort < dist[nrow][ncol]) {
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});          
                    }
                }
            }
        }
        return 0;
    }
};