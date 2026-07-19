class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        int n = strs.size();
        map<string,vector<string>>mpt;
        map<string,string>mpp;
        
        for (int i = 0; i < n; i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            mpt[s].push_back(strs[i]);
        }
        int indx = 0;
        ans.resize(mpt.size());
        for (const auto &[key, it]: mpt) {
            for (auto const &it1: it) {
                ans[indx].push_back(it1);
            }
            indx++;
        }
        return ans;
    }
};