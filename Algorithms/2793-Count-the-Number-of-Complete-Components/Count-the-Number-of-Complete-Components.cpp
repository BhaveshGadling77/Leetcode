class Solution {
public:
    void dfs(int node, vector<int>&vis, vector<vector<int>>&graph, vector<int>&currConnComponent) {
        if (vis[node])
            return;
        
        vis[node] = 1;
        currConnComponent.push_back(node);

        for (int neighbor: graph[node]) {
            dfs(neighbor, vis, graph, currConnComponent);
        }
    }
    
    int helper(vector<vector<int>>&graph, vector<int>&ls) {
        int sum = 0;
        for (int &node: ls) {
            sum += graph[node].size();
        }
        return sum / 2;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        int cnt = 0;
        vector<int>vis(n, 0); // 0 -> not visited 1 -> visited
        for (auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++) {
            vector<int>currConnComponent;
            if (!vis[i]) {
                dfs(i, vis, graph, currConnComponent);
                int res = helper(graph, currConnComponent);
                int m = currConnComponent.size();
                int expectedRes = (m * (m - 1)) / 2;
                if (res == expectedRes)
                    cnt++;
            }
        }
        return cnt;
    }
};