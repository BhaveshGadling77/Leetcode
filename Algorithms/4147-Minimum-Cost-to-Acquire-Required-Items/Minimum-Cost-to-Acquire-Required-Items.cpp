class Solution {
public:
    long long minimumCost(long long cost1, long long cost2, long long costBoth, long long need1, long long need2) {
        long long mini = LLONG_MAX;

        mini = min(mini, (cost1 * need1 * 1LL 
                            + cost2 * need2 * 1LL) * 1LL);
        mini = min(mini, (costBoth * max(need1, need2) * 1LL) * 1LL);
        
        //another way combination of the costBoth and cost1,cost2
        bool isNeed1 = false;
        long long minReq = min(need1, need2);
        long long temp = need1 - minReq;
        if (temp > 0) {
            temp = temp * cost1 * 1LL;
        } else {
            temp = (need2 - minReq) * cost2 * 1LL;
        }

        mini = min(mini, (costBoth * minReq + temp));
        return mini;
    }
};