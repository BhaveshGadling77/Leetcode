class Solution {
public:
    bool isPalindrome(string& str) {
        int left = 0;
        int right = str.length() - 1;

        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    //Recursion
    // int helper(int i, string &s) {
    //     if (i == s.size())
    //         return -1;
    //     string temp = "";

    //     int minCost = INT_MAX;

    //     for (int j = i; j < s.size(); j++) {
    //         temp += s[j];
    //         int cost = INT_MAX;
    //         if (isPalindrome(temp)) {
    //             cost = 1 + helper(j + 1, s);
    //             minCost = min(cost, minCost);
    //         }
    //     }
    //     return minCost;
    // }

    //memoization
    int helper(int i, string &s, vector<int>&dp) {
        if (i == s.size())
            return -1;
        string temp = "";
        if (dp[i] != -1)
            return dp[i];
        int minCost = INT_MAX;

        for (int j = i; j < s.size(); j++) {
            temp += s[j];
            int cost = INT_MAX;
            if (isPalindrome(temp)) {
                cost = 1 + helper(j + 1, s, dp);
                minCost = min(cost, minCost);
            }
        }
        return dp[i] = minCost;
    }
    int minCut(string s) {

        // return helper(0, s); //recursion

        //memoization
        vector<int>dp(s.size() + 1, -1);
        return helper(0, s, dp);
    }
};