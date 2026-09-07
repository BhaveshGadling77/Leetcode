class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        int m = weights.size();
        string s;
        for (auto it: words) {
            char ch = 0;
            int sum = 0;
            for (int i = 0; i < it.size(); i++) {
                int val = weights[it[i] - 'a'];
                val = val % 26;
                sum += val;
            }
            sum  = sum % 26;
            s += 'z' - sum;
        }
        return s;

    }
};