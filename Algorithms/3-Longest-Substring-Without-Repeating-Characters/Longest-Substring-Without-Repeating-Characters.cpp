class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int n = s.size();
        vector<int>hash(256, -1);
        int l = 0, r = 0;
        while (r < n) {
            if (hash[s[r]] != -1) {
                l = max(hash[s[r]] + 1, l);
                // hash[s[r]] = r;
            }
            
            maxLen = max(r-l+1, maxLen);
            hash[s[r]] = r;
            r++;
        }
        maxLen = max(maxLen, r-l);
        return maxLen;
    }
};