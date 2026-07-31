class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<pair<int,int>>mpp(26);
        
        for (int i = 0; i < n; i++) {
            
            if (mpp[word[i]- 'a'].first == 0)
                mpp[word[i] - 'a'].second = i;
            
            mpp[word[i] - 'a'].first++;
        }
        int minCost = 0;
        sort(mpp.begin(), mpp.end(), greater<pair<int,int>>());
        int multiplier = 0;
        for (int i = 0; i < 26; i++) {
            if (mpp[i].first == 0)
                continue;
            
            if (i % 8 == 0)
                multiplier++;
            int freq = mpp[i].first;
            minCost += freq * multiplier;
        }
        return minCost;
    }
};