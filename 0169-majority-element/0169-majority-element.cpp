class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0;
        int ans = nums[0];
        for(auto i : nums) {
            if(freq == 0) {
                freq = 1;
                ans = i;
            }
            else if(i == ans) freq++;
            else freq--;
        }
        return ans;
    }
};