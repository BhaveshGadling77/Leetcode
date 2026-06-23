class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n = s.size();
        int diff = 0;
        for (int i = 1; i < n; i++) {
            diff = abs((s[i]- '0') - (s[i - 1] - '0'));
            if (diff > 2) {
                return false;
            }
        }
        return true;
    }
};