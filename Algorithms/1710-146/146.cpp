class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        int m = load.size();

        vector<int>server(k, 0); // represent current load at ith server
        vector<int>ans; //represent the answer we must return
        // use a min heap to track the server with the earliest finishing time.
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        set<int> available; // represents currently available servers
        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        vector<int>cnt(k,0); //represent cnt of req successfully handled

        // server[0] = load[0];
        // cnt[0]++;
        
        for (int i = 0; i < n; i++) {

            // free the allocation of servers whose requests have finished.
            while (!pq.empty() && pq.top().first <= arrival[i]) {
                int serverId = pq.top().second;
                available.insert(serverId);
                pq.pop();
            }

            // allocate the load to a server
            int reqserver = i % k;

            if (available.empty()) {
                continue; //drop the request
            }

            // find first available server >= reqserver.
            auto it = available.lower_bound(reqserver);

            // circular wrapping of server allocation.
            if (it == available.end()) {
                it = available.begin();
            }

            int serverId = *it;

            available.erase(it); //remove the from available set

            pq.push({arrival[i] + load[i], serverId}); //allocate req

            cnt[serverId]++;
        }

        int maxReqs = *max_element(cnt.begin(), cnt.end());

        for (int i = 0; i < k; i++) {
            if (maxReqs == cnt[i])
                ans.push_back(i);
        }

        return ans;
    }
};