class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        for(auto i : nums) mp[i]++;
        vector<pair<int , int>>ans(mp.begin() , mp.end());
        sort(ans.begin() , ans.end() ,
        [](pair<int , int> &a , pair<int , int> &b) {
            return b.second < a.second;
        });
        vector<int> val;
        for(int i = 0 ; i < k ; i++) val.push_back(ans[i].first);
        return val;
    }
};