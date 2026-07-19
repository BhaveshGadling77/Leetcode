class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int right = nums.size() - 1;
        int left = 0;
        // int len = right + 1;
        // while(right == val) {
        //     right--;
        // }

        while(left < right) {
            if (nums[left] == val) {
                cout << "This is swap" << endl;
                swap(nums[left],nums[right]);
                for(auto it: nums)
                    cout << it << " " << endl;
                right--;
            } else {
                left++;
            }
        }
        for(auto it:nums) {
            cout << it << " ";
        }
        int cnt = 0;
        for (int i = nums.size() - 1; i >= 0 && nums[i] == val;i--) {
            cnt++;
        }
        return len - cnt;
    }
};