class Solution {
public:
    int helper(int node, int d, vector<vector<int>>& adjList,
               vector<int>& depth) {

        depth[node] = d;

        int height = d;

        for (auto neighbor : adjList[node]) {
            height = max(height,
                         helper(neighbor, d + 1, adjList, depth));
        }

        return height;
    }

    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();

        vector<vector<int>> adjList(n);
        vector<int> depth(n);

        for (int i = 1; i < n; i++) {
            int p = parent[i];
            adjList[p].push_back(i);
        }

        int h = helper(0, 1, adjList, depth);

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long d = depth[i];

            ans += 1LL * nums[i] * (h - d + 1);
        }

        return ans;
    }
};