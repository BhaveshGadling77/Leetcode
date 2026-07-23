class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int p = 1;
        while ((p << 1) <= n) p <<= 1;

        if (n <= 2) return n;
        
        return 2 * p;
    }
};