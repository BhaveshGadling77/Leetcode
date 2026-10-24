class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        //simple logic i can think is move left when it is smaller than target
        // move right ptr to the left when curr value becomes large

        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (seen.count(complement)) {
                return {seen[complement], i};
            }

            seen[nums[i]] = i;
        }

        return {-1, -1};
    }
};
