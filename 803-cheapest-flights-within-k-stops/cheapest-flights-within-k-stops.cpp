class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adjList(n, vector<pair<int,int>>(0));
        for (auto fl: flights) {
            adjList[fl[0]].push_back({fl[1], fl[2]});
        } 
        vector<int>dist(n, INT_MAX);
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, 
            greater<pair<int,pair<int,int>>>>pq;
        
        pq.push({0, {src, 0}}); //k,{node, dist}

        while (!pq.empty()) {
            auto it = pq.top();
            int currK = it.first;
            int node = it.second.first;
            int dis = it.second.second;
            pq.pop();
            
            if (currK > k) {
                continue;
            }
            for (auto iter: adjList[node]) {
                
                if (iter.second + dis < dist[iter.first]) {
                    dist[iter.first] = iter.second + dis;
                    pq.push({currK + 1, {iter.first, dist[iter.first]}});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};