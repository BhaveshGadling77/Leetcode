class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // map the values.
        map<string,int>mpp;
        int cnt = 0;
        for (int i = 0; i < equations.size(); i++) {
            for (auto it: equations[i]) {
                if (mpp.find(it) == mpp.end())
                    mpp[it] = cnt++;
            }
        }

        vector<vector<pair<int,double>>>adjList(cnt+1);
        for (int i = 0; i < equations.size(); i++) {
            int u = mpp[equations[i][0]];
            int v = mpp[equations[i][1]];
            double wt = values[i];
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, 1 / wt});
        }
        
        vector<double>ans;
        // if there exist a direct edge then 
        for (auto query: queries) {
            string &from = query[0];
            string &to = query[1];
            bool found = false;
            if (mpp.find(from) == mpp.end() || mpp.find(to) == mpp.end()) {
                ans.push_back(-1);
                continue;
            }
            
            int u = mpp[from];
            int v = mpp[to];
            // cout << from << " " << to << endl;
            if (u == v) {
                ans.push_back(1.0);
                continue;
            }

            queue<pair<double, int>>q;
            q.push({1, u});
            vector<int>vis(cnt + 1, 0);
            vis[u] = 1;
            while (!q.empty()) {
                int node = q.front().second;
                double parentWt = q.front().first;
                q.pop();
                vis[node] = 1;
                if (node == v) {
                    ans.push_back(parentWt);
                    found = true;
                    break;
                }
                
                for (auto it : adjList[node]) {
                    int neighbor = it.first;
                    double wt = it.second;

                    if (!vis[neighbor]) {
                        vis[neighbor] = 1;
                        q.push({parentWt * wt, neighbor});
                    }
                }
            }
            if (!found)
                ans.push_back(-1);
        }

        return ans;
    }
};