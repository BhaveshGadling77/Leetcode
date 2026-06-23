class Solution {
public:
    vector<vector<int>> ans;

    void dfs(int node, int target, vector<int>& path, vector<vector<int>>& graph) {
        if (node == target) {
            ans.push_back(path);
            return;
        }

        for (auto next : graph[node]) {
            path.push_back(next);
            dfs(next, target, path, graph);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        path.push_back(0);
        dfs(0, graph.size() - 1, path, graph);
        return ans;
    }
};