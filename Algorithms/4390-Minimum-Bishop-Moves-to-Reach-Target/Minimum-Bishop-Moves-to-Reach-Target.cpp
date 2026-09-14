class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int sr = source[0];
        int sc = source[1];

        int dr = target[0];
        int dc = target[1];

        if (((sr + sc) % 2) == (dr + dc) % 2) {

            if (abs(sr - dr) == abs(sc - dc)) {
                return 1;
            } else {
                return 2;
            }

        } else {
            return -1;
        }
    }
};