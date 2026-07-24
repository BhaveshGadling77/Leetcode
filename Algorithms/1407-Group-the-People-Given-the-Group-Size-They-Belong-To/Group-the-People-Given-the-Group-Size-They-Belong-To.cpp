class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gr) {
        int n = gr.size();
        vector<vector<int>>ans;
        map<int, vector<pair<int,int>>>mpp;
        
        for (int i = 0; i < n; i++) {
            mpp[gr[i]].push_back({gr[i], i});
        }
        
        for (auto &[el, it]: mpp) {
            int cnt = 0;
            vector<int>temp;
            for (int i = 0; i < it.size(); i++) {
                if (cnt == gr[it[i].second]) {
                    cnt = 0;

                    ans.push_back(temp);
                    temp.clear();
                }
                temp.push_back(it[i].second);
                cnt++;
            } 
            ans.push_back(temp);
        }
        return ans;
    }
};