class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp = arr;
        map<int,int>mpp;
        vector<int>ans;
        sort(temp.begin(), temp.end());
        int rank = 1;
        for (int x : temp) {
            if (mpp.find(x) == mpp.end()) {
                mpp[x] = rank++;
            }
        }

        for (int x : arr)
            ans.push_back(mpp[x]);
        return ans;
    }
};