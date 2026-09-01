class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int str = start[0];
        int stc = start[1];
        int tr = target[0];
        int tc = target[1];

        return abs(str - tr) % 2 == abs(tc - stc) % 2;
    }
};