class DisjointSet {
	vector<int>rank, parent;
	public:
		DisjointSet(int n) {
			rank.resize(n, 0);
			parent.resize(n);
			//mark all the nodes as they are the parents of itself.
			for (int i = 0; i < n; i++) {
				parent[i] = i;
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
        int findComponents() {
            int n = parent.size();
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (parent[i] == i) {
                    cnt++;
                }
            }
            return cnt;
        }

};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& conn) {
        DisjointSet ds(n);
        int extraEdges = 0;
        for (auto con: conn) {
            if (ds.findParent(con[0]) != ds.findParent(con[1])) {
                ds.unionByRank(con[0], con[1]);
            } else {
                extraEdges++;
            }
        }
        int ans = ds.findComponents() - 1;
        if (ans <= extraEdges) {
            return ans;
        }
        return -1;
    }
};