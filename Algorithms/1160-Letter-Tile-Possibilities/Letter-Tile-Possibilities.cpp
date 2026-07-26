class Solution {
public:
    int dfs(string s, vector<int>&mpp) {
        int cnt = 0;
        for (int i = 0; i < mpp.size(); i++) {
            if (mpp[i] == 0) {
                continue;
            }
            
            mpp[i]--;
            char ch = i + 'A';
            cnt++;
            cnt += dfs(s + ch, mpp);
            mpp[i]++;
        }
        return cnt;
    }
    int numTilePossibilities(string tiles) {
        
        vector<int>mpp(26, 0);
        for (char ch:tiles) {
            mpp[ch - 'A']++;
        }
        return dfs("", mpp);
    }
};