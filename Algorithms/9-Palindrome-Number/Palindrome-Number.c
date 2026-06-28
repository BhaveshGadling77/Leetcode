bool isPalindrome(int x) {
    int temp = x;
    long rem = 0, new = 0;
    if(x < 0){
        return false;
    }
    for(int i = 0; x > 0; i++){
        rem = x % 10;
        new = new * 10 + rem;
        x = x / 10;
    }
    if(temp == new){
        return true;
    }
    return false;
}