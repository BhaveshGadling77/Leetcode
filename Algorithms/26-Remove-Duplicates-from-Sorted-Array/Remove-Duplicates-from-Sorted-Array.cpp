class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int i = 0;
        // for (int it = nums.begin(); it != nums.end(); it++) {
        //     if(nums[it] != nums[i]) {
        //         nums[i+1] = nums[it];
        //         i++;
        //     } 
        // }
        int i = 0;
        int len = nums.size();
        for (int j = 0; j < len; j++)  {
            if (nums[i] != nums[j] && i < len) {
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;
    }
};