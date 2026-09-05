class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxi = nums[0];
        int n = nums.size();
        vector<int>mini(n);
        int x = nums[n - 1];
        for(int i = n - 1 ; i >= 0 ; i--) {
            x = min(x , nums[i]);
            mini[i] = x;
        }
        for(int i = 0 ; i < nums.size() ; i++) {
            maxi = max(maxi , nums[i]);
            if(maxi - mini[i] <= k) return i;
        }
        return -1;
    }
};