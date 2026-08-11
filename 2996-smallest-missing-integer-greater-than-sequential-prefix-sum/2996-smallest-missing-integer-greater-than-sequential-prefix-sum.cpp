class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int count = 1;
        map<int , int> mp;
        for(auto i : nums) mp[i]++;
        for(int i = 1 ; i < nums.size() && nums[i] == nums[i - 1] + 1 ; i++) count = i + 1;
        int ans = count * (nums[count - 1] + nums[0]) / 2;
        while(mp.find(ans) != mp.end()) ans++;
        return ans;
    }
};