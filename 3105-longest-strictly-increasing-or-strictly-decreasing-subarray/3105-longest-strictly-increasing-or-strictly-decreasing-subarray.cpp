class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        int ans = 1 , count = 1;
        for(int i = 1 ; i < n ; i++) {
            if(nums[i] > nums[i - 1]) {
                count++;
                ans = max(ans , count);
            }
            else count = 1;
        }
        count = 1;
        for(int i = 1 ; i < n ; i++) {
            if(nums[i] < nums[i - 1]) {
                count++;
                ans = max(ans , count);
            }
            else count = 1;
        }
        return ans;
    }
};