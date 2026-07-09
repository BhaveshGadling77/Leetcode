class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector <int> ans(nums.size(), 0);
        int indx1 = 0, indx2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                ans[2 * indx2 + 1] = nums[i];
                indx2++; 
            } else {
                ans[2 * indx1] = nums[i];
                indx1++;
            }
        }
        return ans;
    }
};