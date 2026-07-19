class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        digits[n-1] += 1;
        vector<int>vis(n, 0);
        bool check = false;
        
        for (int i = n-1; i >= 1; i--) {
            if (digits[i] == 0)
                continue;
            digits[i] = digits[i] % 10;
            if (digits[i] == 0) {
                digits[i-1]++;
            }
        }
        digits[0] = digits[0] % 10;
        if (digits[0] == 0) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};