class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        map<int,int>mpp;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
            maxi = max(nums[i], maxi);
            mini = min(nums[i], mini);
        }

        
        for (int i = mini + 1; i <= maxi-1; i++) {
            if (mpp.find(i) == mpp.end())
                ans.push_back(i);
        }
        return ans;
    }
};