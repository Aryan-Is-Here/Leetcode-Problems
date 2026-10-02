class Solution {
public:
    int uniquePaths(int m, int n) {
        int check[m][n];
        for(int i = 0 ; i < m ; i++) check[i][0] = 1;
        for(int j = 0 ; j < n ; j++) check[0][j] = 1;
        for(int i = 1 ; i < m ; i++) for(int j = 1 ; j < n ; j++) check[i][j] = check[i - 1][j] + check[i][j - 1];
        return check[m - 1][n - 1];
    }
};