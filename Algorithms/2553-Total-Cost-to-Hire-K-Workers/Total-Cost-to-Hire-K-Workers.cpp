class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int cand) {
        int n = costs.size();
        
        //for right partition
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>rq;
        
        // for left partition
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>lq;
        long long ans = 0;
        int left = 0;
        int right = n - 1;

        for (int i = 0; i < cand && left <= right; i++) {
            lq.push({costs[left], left});
            left++;
        }

        for (int i = 0; i < cand && left <= right; i++) {
            rq.push({costs[right], right});
            right--;
        }
        left = cand;
        right = n - cand - 1;
        while (k--) {
            if (rq.empty()) {
                auto cur = lq.top();
                lq.pop();
                ans += cur.first;

                if (left <= right) {
                    lq.push({costs[left], left});
                    left++;
                }
            }
            else if (lq.empty()) {
                auto cur = rq.top();
                rq.pop();
                ans += cur.first;

                if (left <= right) {
                    rq.push({costs[right], right});
                    right--;
                }
            }
            else {
                if (lq.top().first <= rq.top().first) {
                    auto cur = lq.top();
                    lq.pop();
                    ans += cur.first;

                    if (left <= right) {
                        lq.push({costs[left], left});
                        left++;
                    }
                }
                else {
                    auto cur = rq.top();
                    rq.pop();
                    ans += cur.first;

                    if (left <= right) {
                        rq.push({costs[right], right});
                        right--;
                    }
                }
            }
            
        }
        return ans;

    }
};