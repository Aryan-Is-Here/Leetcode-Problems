class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        nums[0] = nums[0] * nums[0];
        for(int i = 1 ; i < nums.size() ; i++) if(nums.size() % (i + 1) == 0) nums[0] += nums[i] * nums[i];
        return nums[0];
    }
};