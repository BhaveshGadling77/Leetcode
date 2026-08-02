class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int sumA = 0;
        int sumB = 0;
        int n = piles.size();
        for (int i = 0; i < n / 2; i++) {
            sumA += piles[n - i - 1];
            sumB += piles[i];
        }
        return sumA > sumB ? true : false;
    }
};