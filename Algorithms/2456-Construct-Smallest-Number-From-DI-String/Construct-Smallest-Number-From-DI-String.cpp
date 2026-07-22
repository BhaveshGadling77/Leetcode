class Solution {
public:
    string ans = "";
    bool found = false;

    void helper(int idx, string &curr, string &pattern, vector<bool> &used) {
        if (found) return;

        if (idx == pattern.size() + 1) {
            ans = curr;
            found = true;
            return;
        }

        for (int d = 1; d <= 9; d++) {
            if (used[d]) continue;

            if (idx > 0) {
                char prev = curr.back();

                if (pattern[idx - 1] == 'I' && !(prev < ('0' + d)))
                    continue;

                if (pattern[idx - 1] == 'D' && !(prev > ('0' + d)))
                    continue;
            }

            used[d] = true;
            curr.push_back('0' + d);

            helper(idx + 1, curr, pattern, used);

            curr.pop_back();
            used[d] = false;
        }
    }

    string smallestNumber(string pattern) {
        vector<bool> used(10, false);
        string curr = "";

        helper(0, curr, pattern, used);

        return ans;
    }
};