class Solution {
public:
    int digitFrequencyScore(int n) {
        map<int,int>mpp;
        
        while (n > 0) {
            int digit = n % 10;
            n = n / 10;
            mpp[digit]++;
        }
        int score = 0;
        for (auto it: mpp) {
            int digit = it.first;
            int freq = it.second;
            score += digit * freq;
        }
        return score;
    }
};