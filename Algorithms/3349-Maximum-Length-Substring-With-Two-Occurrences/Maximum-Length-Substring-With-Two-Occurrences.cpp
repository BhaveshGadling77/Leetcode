class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxi = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            map<int,int>mpp;
            for (int j = i; j < n; j++) {
                mpp[s[j]]++;
                if (mpp[s[j]] > 2) {
                    break;
                }
                maxi = max(j - i + 1, maxi);
            }
        }
        return maxi;
    }
};