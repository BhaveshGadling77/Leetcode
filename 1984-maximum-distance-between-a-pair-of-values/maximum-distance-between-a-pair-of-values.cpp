class Solution {
public:
    int helper(vector<int>&nums2, int left, int ref) {
        int right = nums2.size()-1;
        int ans = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            // cout << mid << endl;
            
            if (ref <= nums2[mid]) {
                left = mid + 1;
                ans = mid;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int left = 0;
        int right = 0;
        int maxi = 0;
        while(left < n) {
            int indx = helper(nums2, left, nums1[left]);
            // cout << indx << " ";
            maxi = max(maxi, indx - left);
            left++;
        }
        return maxi;
    }
};