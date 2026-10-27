class Solution {
public:
    vector<string> createGrid(int m, int n) {
        int x = 0;
        string s = "";
        for(int j = 0 ; j < n ; j++) s += '#';
        vector<string> grid(m , s);
        for(int i = 0 ; i < m ; i++) grid[i][0] = '.';
        for(int j = 0 ; j < n ; j++) grid[m - 1][j] = '.';
        return grid;
    }
};