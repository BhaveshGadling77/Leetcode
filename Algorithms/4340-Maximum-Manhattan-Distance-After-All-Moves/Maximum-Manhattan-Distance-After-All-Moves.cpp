class Solution {
public:
    int maxDistance(string moves) {
        int n = moves.size();
        int y = 0;
        int x = 0;
        vector<vector<int>>dir = {{-1, 0}, {1, 0},{0, -1}, {0, 1}};
        int maxX = 0;
        int maxY = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            char currChar = moves[i];
            if (currChar == 'U') {
                x += dir[0][0];
                y += dir[0][1];
            } else if (currChar == 'D') {
                x += dir[1][0];
                y += dir[1][1];
            } else if (currChar == 'L') {
                x += dir[2][0];
                y += dir[2][1];
            } else if (currChar == 'R'){
                x += dir[3][0];
                y += dir[3][1];
            } else {
                cnt++;
            }
        }
        // cout << x << y << endl;
        if (x < 0) {
            x += cnt * -1;
        } else if (x > 0) {
            x += cnt;
        } else if (y < 0) {
            y += cnt * -1;
        } else {
            y += cnt;
        }
        int dist = abs(x) + abs(y);
        return dist;
    }
};