class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int temp = x, digit = 0, num = 0;
        while (x > 0) {
            digit = x % 10;
            if (num > Integer.MAX_VALUE / 10 || (num == Integer.MAX_VALUE / 10 && digit > 7)) return false;
            if (num < Integer.MIN_VALUE / 10 || (num == Integer.MIN_VALUE / 10 && digit < -8)) return false;
            num = num * 10 +  digit;
            x /= 10;
    }
        return temp == num ? true : false;
    }
}