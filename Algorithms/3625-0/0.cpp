class Solution {
public:
    bool canAliceWin(int n) {
        if (n < 10)
            return false;
        
        // simulate the question
        int remove = 10;
        bool isaliceTurn = true;

        while (n >= remove) {
            n -= remove;
            remove--; //second condition in question 
            isaliceTurn = !isaliceTurn;
        }

        return !isaliceTurn;
    }
};