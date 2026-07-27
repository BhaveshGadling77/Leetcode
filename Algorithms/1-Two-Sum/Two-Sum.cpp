class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
          map <int, int> mpp;
        int rem, n = nums.size();
        for (int i = 0; i < n; i++) {
                        rem = target - nums[i];
                        if(mpp.find(rem) != mpp.end()) {
                            return {(mpp.at(rem)), i};
                        }
                        mpp[nums[i]] = i;
                if (nums[i] > target)
                        continue;
        }
        return {-1, 1};

    }
};