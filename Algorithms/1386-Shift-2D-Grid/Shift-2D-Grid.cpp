class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int>fg;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                fg.push_back(grid[i][j]);
        k = k % fg.size();
        //reverse(fg.begin(), );
        vector<int> temp;
        for(int i=fg.size()-k;i<fg.size();i++){
            temp.push_back(fg[i]);
        }
        for(int z=0;z<fg.size()-k;z++){
            temp.push_back(fg[z]);
        }
        
        int s = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                grid[i][j] = temp[s++];
        
        return grid;
    }
};