class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        long long revenue = 0;
        int fdn = 0;
        int tdn = 0;
        int twdn = 0;
        for (int i = 0; i < n; i++) {
            if (bills[i] == 5) {
                fdn += 1;
            } else {
                if (bills[i] == 10) {
                    tdn += 1;
                    fdn--;
                } else if (bills[i] == 20) {
                    if (tdn > 0 && fdn > 0) {
                        tdn--;
                        fdn--;
                    } else if (fdn < 3) {
                        return false;
                    } else {
                        fdn -=3;
                    }
                }
                if (tdn < 0 || fdn < 0 || twdn < 0)
                    return false;
            }
        }
        return true;
    }
};