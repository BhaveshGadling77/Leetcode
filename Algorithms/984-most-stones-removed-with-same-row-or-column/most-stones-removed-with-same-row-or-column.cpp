class DisjointSet {
	vector<int>rank, parent, size;
	public:
		DisjointSet(int n) {
			rank.resize(n+1, 0);
            size.resize(n+1, 0);
			parent.resize(n+1);
			//mark all the nodes as they are the parents of itself.
			for (int i = 0; i <= n; i++) {
				parent[i] = i;
                size[i] = 1;
			}

		}
		int findParent(int node) {
			if (node == parent[node]) {
				return node;
			}
			return parent[node] = findParent(parent[node]);
		}

		void unionByRank(int u, int v) {
			int ulp_u = findParent(u);
			int ulp_v = findParent(v);
			if (ulp_u == ulp_v) {
				return;
			}

			if (rank[ulp_u] < rank[ulp_v]) {
				parent[ulp_u] = ulp_v;
			}
			else if (rank[ulp_v] < rank[ulp_u]) {
				parent[ulp_v] = ulp_u;
			} else {
				parent[ulp_v] = ulp_u;
				rank[ulp_u]++;
			}
		}
        void unionBySize(int u, int v) {
			int ulp_u = findParent(u);
			int ulp_v = findParent(v);
			if (ulp_u == ulp_v) {
				return;
			}
			if (size[ulp_u] < size[ulp_v]) {
				size[ulp_v] = size[ulp_v] + size[ulp_u];
				parent[ulp_u] = ulp_v;
			} else if (size[ulp_u] > size[ulp_v]) {
				size[ulp_u] = size[ulp_v] + size[ulp_u];
				parent[ulp_v] = ulp_u;
			} else {
				size[ulp_u] = size[ulp_v] + size[ulp_u];
				parent[ulp_v] = ulp_u;
			}
		}

};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;
        int n = stones.size();
        for (auto it: stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int,int>stoneNodes;

        for (auto it: stones) {
            int nodeRow = it[0];
            int nodeCol = it[1]+ maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        int cnt = 0;
        for (auto it: stoneNodes) {
            if (ds.findParent(it.first) == it.first) {
                cnt++;
            }
        }
        return n - cnt;
    }
};