class Solution {
public:
    int elevatorRequests(int n, vector<int>& req) {
        int cnt = req[0];

        for (int i = 1; i < req.size(); i++) {
            cnt += abs(req[i] - req[i - 1]);
        }
        return cnt;
    }
};