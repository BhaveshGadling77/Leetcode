class Solution {
public:

    void helper(vector<string> &ans, int open, int close, string p) {
        if (close == 0) {
            ans.push_back(p);
            return;
        }
        
        if (open)
            helper(ans, open - 1, close, p + '(');
        if (open < close)
            helper(ans, open, close-1, p + ')');
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans, n, n, "");
        return ans;
    }
};