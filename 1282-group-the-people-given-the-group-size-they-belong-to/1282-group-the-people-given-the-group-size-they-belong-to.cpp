class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>>ans;
        unordered_map<int , vector<int>>mp;
        int n = groupSizes.size();
        for(int i = 0 ; i < n ; i++) {
            mp[groupSizes[i]].push_back(i);
            if(mp[groupSizes[i]].size() == groupSizes[i]) {
                ans.push_back(mp[groupSizes[i]]);
                mp.erase(groupSizes[i]);
            }
        }
        return ans;
    }
};