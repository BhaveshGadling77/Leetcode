class DisjointSet {
	vector<int>rank, parent, size;
	public:
		DisjointSet(int n) {
			rank.resize(n+1, 0);
			size.resize(n+1, 1);
			parent.resize(n+1);
			//mark all the nodes as they are the parents of itself.
			for (int i = 0; i <=n; i++) {
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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DisjointSet *ds = new DisjointSet(n);
        vector<bool>ans;
        for (int i = 0; i < n - 1; i++) {
            if (abs(nums[i] - nums[i + 1]) <= maxDiff) {
                ds->unionBySize(i, i + 1);
            }
        }
        
        for (auto &it: queries) {
            int u = it[0];
            int v = it[1];
            if (ds->findParent(u) == ds->findParent(v)) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};