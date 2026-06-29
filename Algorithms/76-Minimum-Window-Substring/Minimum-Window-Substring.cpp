class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0,stIndx = -1, r = 0, cnt = 0, minLen = INT_MAX,n = s.size(), m = t.size();
        vector<int>hash(257, 0);
        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }
        while (r < n) {
            if (hash[s[r]] > 0) {
                cnt++;
            }
            hash[s[r]]--;
            while (cnt == m) {
                if (r - l + 1 < minLen) {
                    minLen = r -l +1;
                    stIndx = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return stIndx == -1 ? "" : s.substr(stIndx, minLen) ;
    }
};