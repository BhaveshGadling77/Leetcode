class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        int n = n1 + n2;
        int indx2 = n / 2;
        int indx1 = indx2 - 1;
        int cnt = 0, i = 0, j =0;
        int ind1el = -1, ind2el = -1;
        while (i < n1 && j < n2) {
            if (arr1[i] < arr2[j]) {
                if (cnt == indx1) ind1el = arr1[i];
                if (cnt == indx2) ind2el = arr1[i];
                cnt++;
                i++;
            } else {
                if (cnt == indx1) ind1el = arr2[j];
                if (cnt == indx2) ind2el = arr2[j];
                cnt++;
                j++;
            }
        }
        while (i < n1) {
            if (cnt == indx1) ind1el = arr1[i];
            if (cnt == indx2) ind2el = arr1[i];
            cnt++;
            i++;
        }
        while (j < n2) {
            if (cnt == indx1) ind1el = arr2[j];
            if (cnt == indx2) ind2el = arr2[j];
            cnt++;
            j++;
        }
        if (n % 2 == 1) {
            return ind2el;
        }
        return (double) ((double) (ind1el + ind2el)) / 2;
    }
};