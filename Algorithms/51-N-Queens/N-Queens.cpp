class Solution {
public:
    bool isSafe(vector<string> &board, int r, int c) {
        // check upward
        for (int i = 0; i < r; i++) {
            if (board[i][c] == 'Q') {
                return false;
            }
        }

        //check left diagonally.
        int minLeft = min(r, c);
        for (int i = 1; i <= minLeft; i++) {
            if (board[r-i][c-i] == 'Q') {
                return false;
            }
        }

        //check for right diagonally.
        int s = board.size() - c - 1;
         minLeft = min(r, s);
        for (int i = 1; i <= minLeft; i++) {
            if (board[r-i][c+i] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void solve(vector<vector<string>> &ans, int r, 
    vector<string> &board) {
        if (r == board.size()) {
            ans.push_back(board);
            return;
        }
        int n = board.size();
        for (int c = 0; c < n; c++) {
            if (isSafe(board, r, c)) {
                board[r][c] = 'Q';
                solve(ans, r + 1, board);
                board[r][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s = "";
        for (int i = 0; i < n; i++) {
            s += '.';
        }
        
        vector<vector<string>> ans;
        vector<string>board(n, s);
        solve(ans, 0, board);
        return ans;
    }
};