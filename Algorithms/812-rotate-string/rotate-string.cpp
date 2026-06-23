class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();
        string t = s;
        for (int i = 0; i < n; i++) {
            if (s == goal)
                return true;
            
            char temp = s[0];
            s += temp;
            if (!s.empty()) {

                s.erase(0, 1);
            }
        }
        return false;
    }
};