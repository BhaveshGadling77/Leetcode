class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int col = colors[0];
        int maxi = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (col != colors[i]) {
                maxi = max(maxi, i);
                break;
            }
        }
        col = colors[n-1];
        for (int i = 0; i < n; i++) {
            if (col != colors[i]) {
                maxi = max(maxi, n-1-i);
            }
        }
        return maxi;
    }
};