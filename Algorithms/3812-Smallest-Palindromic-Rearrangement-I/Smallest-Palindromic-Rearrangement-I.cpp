class Solution {
public:
    string smallestPalindrome(string s) {
        if (s.size() == 1)
            return s;
        
        int n = s.size();
        int mid = n / 2;
        sort(s.begin(), s.begin() + mid);
        // sort(s.begin() + mid, s.end(), [](char a, char b){
        //     return a >= b;
        // });
        int k = 0;
        for (int i = n - 1; i >= mid; i--) {
            s[i] = s[k++];
        }
        return s;
    }
};