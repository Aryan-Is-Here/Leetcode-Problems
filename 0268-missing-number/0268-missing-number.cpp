class Solution {
public:
    int missingNumber(vector<int>& nums) {
        nums.push_back(-1);
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] == -1) i++;
            else {
                if(nums[i] == i) i++;
                else swap(nums[i] , nums[nums[i]]);
            }
        }
        for(int i = 0 ;  i < nums.size() ; i++) if(nums[i] == -1) return i;
        return -1;
    }
};