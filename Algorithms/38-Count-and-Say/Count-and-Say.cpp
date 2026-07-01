class Solution {
public:
    vector<pair<int,int>> helper1(string s) {
        char curr = s[0];
        int cnt = 0;
        int n = s.size();
        vector<pair<int,int>>ans;
        for (int i = 0; i < n; i++) {
            if (curr == s[i]) {
                cnt++;
            } else {
                pair<int,int> p = {curr - '0', cnt};
                ans.push_back(p);
                curr = s[i];
                cnt = 1;
            }
        }
        pair<int,int> p = {curr - '0', cnt};
        ans.push_back(p);
        return ans;
    }

    string helper2(vector<pair<int,int>>&p) {
        string ans = "";
        for (int i = 0; i < p.size(); i++) {
            int curr = p[i].first;
            int cnt = p[i].second;
            ans += (cnt + '0');
            ans += (curr + '0');
        }
        return ans;
    }
    string helper(int i, int n, string s) {
        if (i == n)
            return s;
        
        vector<pair<int,int>> p= helper1(s);
        string st = helper2(p);
        cout <<st << endl;
        return helper(i + 1, n, st);
    }
    string countAndSay(int n) {
        return helper(1,n, "1");
    }
};