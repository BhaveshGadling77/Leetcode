class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for (string &s: patterns) {
            if (string::npos != word.find(s))
                cnt++;
        }
        return cnt;
    }
};