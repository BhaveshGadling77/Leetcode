class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>hash(26, 0);
        int n = s.size();
        for (int i = 0; i < n; i++) 
            hash[s[i] - 'a']++;
        
        for (int i = 0; i < n; i++) {
            if (hash[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};