class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() , m = grid[0].size() , count = 0;
        queue<pair<int , int>>q;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == '1') {
                    count++;
                    q.push({i , j});
                    while(!q.empty()) {
                        int x = q.front().first , y = q.front().second;
                        if(grid[x][y] == '0') {
                            q.pop();
                            continue;
                        }
                        if(x < n - 1 && grid[x + 1][y] == '1') q.push({x + 1 , y});
                        if(y < m - 1 && grid[x][y + 1] == '1') q.push({x , y + 1});
                        if(x > 0 && grid[x - 1][y] == '1') q.push({x - 1 , y});
                        if(y > 0 && grid[x][y - 1] == '1') q.push({x , y - 1});
                        grid[x][y] = '0';
                        q.pop();
                    }
                }
            }
        }
        return count;
    }
};