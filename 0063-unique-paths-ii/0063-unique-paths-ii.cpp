class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size() , n = obstacleGrid[0].size();
        vector<vector<int>>grid(m , vector<int>(n , 0));
        for(int i = 0 ; i < m ; i++) {
            if(!obstacleGrid[i][0]) grid[i][0] = 1;
            else break;
        }
        for(int j = 0 ; j < n ; j++) {
            if(!obstacleGrid[0][j]) grid[0][j] = 1;
            else break;
        }
        for(int i = 1 ; i < m ; i++) {
            for(int j = 1 ; j < n ; j++) {
                if(!obstacleGrid[i][j]) grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
            }
        }
        return grid[m - 1][n - 1];
    }
};