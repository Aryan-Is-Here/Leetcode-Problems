class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        for(auto i : nums) mp[i]++;
        vector<pair<int , int>>ans;
        int n = mp.size();
        for (auto &it : mp) ans.push_back({it.second, it.first});
        sort(ans.begin() , ans.end());
        vector<int> val;
        for(int i = n - 1 ; i >= n - k ; i--) val.push_back(ans[i].second);
        return val;
    }
};