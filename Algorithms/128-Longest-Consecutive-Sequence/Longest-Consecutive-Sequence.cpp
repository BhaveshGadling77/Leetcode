class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for (int num : st) {

            if (st.find(num - 1) == st.end()) {
                int currentNum = num;
                int currentLength = 1;
                while (st.find(currentNum + 1) != st.end()) {
                    currentNum++;
                    currentLength++;
                }

                longest = max(longest, currentLength);
            }
        }

        return longest;
    }
};