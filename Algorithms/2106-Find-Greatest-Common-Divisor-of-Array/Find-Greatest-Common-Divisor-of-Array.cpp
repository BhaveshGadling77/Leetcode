class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxGCD = nums[0];

        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(), nums.end());

        return gcd(maxi, mini);
    }
};