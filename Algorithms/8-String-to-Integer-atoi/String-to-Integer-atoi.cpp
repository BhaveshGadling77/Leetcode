class Solution {
public:
    int myAtoi(string s) {
        long long res = 0;
        int n = s.size();
        int i = 0;
        int sign = 1;

        while (i < n && s[i] == ' ')
            i++;

        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            i++;
        }

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            res = res * 10 + digit;
            i++;
        }

        return sign * res;
    }
};
