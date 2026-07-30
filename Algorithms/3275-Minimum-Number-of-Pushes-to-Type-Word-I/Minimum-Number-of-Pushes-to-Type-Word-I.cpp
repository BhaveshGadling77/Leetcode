class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        
        map<char,int>mpp;

        for (int i = 0; i < n; i++) {
            mpp[word[i]]++;
        }
        int multiplier = 1;
        int minCost = 0;
        int cnt = 0;
        for (auto it: mpp) {
            if (cnt > 0 && cnt % 8 == 0)
                multiplier++;
            minCost += multiplier * it.second;
            cnt++;
        }
        return minCost;
    }
};