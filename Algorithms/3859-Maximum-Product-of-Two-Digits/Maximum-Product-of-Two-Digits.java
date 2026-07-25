class Solution {
    public int maxProduct(int n) {
        int max1,max2,digit;
        max1 = max2 = Integer.MIN_VALUE;
        digit = 0;
        while(n>0){
            digit = n % 10;
            if(digit>max2 && digit<=max1){
                max2 = digit;
            }
            else if(digit>max1){
                max2 = max1;
                max1 = digit;
            }
            n = n/10;
        }       
        return max1*max2;
    }

    
}