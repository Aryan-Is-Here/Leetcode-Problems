class Solution {
public:
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1, T2> &p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1 ^ (h2 << 1); 
        }
    };
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        queue<pair<int , int>>q;
        unordered_map<pair<int , int> , int , pair_hash> mp;
        for(int i = 0 ; i < grid.size() ; i++) {
            for(int j = 0 ; j < grid[0].size() ; j++) {
                if(grid[i][j] == 1 && mp.find({i , j}) == mp.end()) {
                    int area = 0;
                    q.push({i , j});
                    mp[{i , j}] = 1;
                    while(!q.empty()) {
                        auto t = q.front();
                        int x = t.first , y = t.second;
                        q.pop();
                        if(x > 0 && grid[x - 1][y] == 1 && mp.find({x - 1 , y}) == mp.end()) {
                            mp[{x - 1 , y}] = 1;
                            q.push({x - 1 , y});
                        }
                        if(y > 0 && grid[x][y - 1] == 1 && mp.find({x , y - 1}) == mp.end()) {
                            mp[{x , y - 1}] = 1;
                            q.push({x , y - 1});
                        }
                        if(x < grid.size() - 1 && grid[x + 1][y] == 1 && mp.find({x + 1 , y}) == mp.end()) {
                            mp[{x + 1 , y}] = 1;
                            q.push({x + 1 , y});
                        }
                        if(y < grid[0].size() - 1 && grid[x][y + 1] == 1 && mp.find({x , y + 1}) == mp.end()) {
                            mp[{x , y + 1}] = 1;
                            q.push({x , y + 1});
                        }
                        area++;
                    }
                    ans = max(ans , area);
                }
            }
        }
        return ans;
        
    }
};