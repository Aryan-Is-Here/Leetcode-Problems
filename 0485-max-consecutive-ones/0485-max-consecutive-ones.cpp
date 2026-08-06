class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count = 0 , count = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            if(nums[i]) count++;
            else {
                max_count = max(max_count , count);
                count = 0;
            }
        }
        return max(max_count , count);
    }
};