class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int mini = 0; // minimum  '(' bracket till index i;
        int maxi = 0; // maximum '(' bracket till index i;

        for (int i = 0; i < n; i++) {

            // at '(' increase the both the number
            if (s[i] == '(') {
                mini++;
                maxi++;
            } else if (s[i] == ')') {
                mini--;
                maxi--;
                //decrease because it will pop that
            } else {
                mini++;
                maxi--;
            }

            if (maxi < 0) {
                maxi = 0;
            }
            if (mini < 0) 
                return false;
        }
        if (maxi == 0)
            return true;
        return false;
    }

};