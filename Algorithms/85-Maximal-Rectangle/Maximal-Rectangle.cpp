class Solution {
public:
    int largeRect(vector<int>& height) {
        stack<int>st;
        int n = height.size();
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[st.top()] > height[i]) {
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(height[element] * (nse - pse-1), maxArea);
            }
            st.push(i);
        }
        while (!st.empty()) {
            int nse = n;
            int el = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, height[el] * (nse - pse - 1));
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>preMat(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += (matrix[i][j] -'0');
                if (matrix[i][j] =='0')
                    sum = 0;
                preMat[i][j] = sum;
            }
        }
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, largeRect(preMat[i]));
        }
        return maxArea;
    }
};