class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int len = nums.size();
        map<int, int> mpp;
        for (int i = 0; i < len; i++) {
            mpp[nums[i]]++;
        }
        
        int res = k;
        while (1) {
            if (mpp.find(res) == mpp.end()) {
                return res;
            }
            res = res + k;
        }
        return k;
    }
};