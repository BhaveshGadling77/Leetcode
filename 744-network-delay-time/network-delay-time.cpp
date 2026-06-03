class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adjList(n+1);
        
        for (auto edge: times) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int>dist(n+1, INT_MAX);
        dist[k] = 0;
        dist[0] = 0;
        pq.push({ 0, k});
        while (!pq.empty()) {
            auto p = pq.top();
            int node = p.second;
            int dis = p.first;
        
            pq.pop();
            if (dis > dist[node])
                continue;
            for (auto it: adjList[node]) {
                int newNode = it.first;
                int newWt = it.second;

                if (newWt + dis < dist[newNode]) {
                    dist[newNode] = newWt + dis;
                    pq.push({dist[newNode], newNode});
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            
            if (dist[i] == INT_MAX) {
                return -1;
            }
            ans = max(dist[i], ans);
        }
        return ans;
    }
};