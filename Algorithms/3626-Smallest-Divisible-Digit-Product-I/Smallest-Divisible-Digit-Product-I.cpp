class Solution {
public:
    
    int smallestNumber(int n, int t) {
        
        for (int i = n; i <= n + 10; i++) {
            int rem = 0;
            int prod = 1;
            int org = i;
            while(i != 0) {
                rem = i % 10;
                i = i / 10;
                prod = rem * prod;
            }
            i = org;
            if (prod % t == 0)
                return org;
        }
        return -1;
    }
};