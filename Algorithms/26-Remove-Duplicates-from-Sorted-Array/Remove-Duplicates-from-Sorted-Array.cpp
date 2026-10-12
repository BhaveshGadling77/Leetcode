class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int i = 0;
        for (int j = 0; j < len; j++)  {
            if (nums[i] != nums[j] && i < len) {
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;

    }
};