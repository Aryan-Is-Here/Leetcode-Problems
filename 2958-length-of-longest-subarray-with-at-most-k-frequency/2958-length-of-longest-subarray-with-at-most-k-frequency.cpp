class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int , int> check;
        int low = 0 , high = 0;
        int ans = 0;
        while(high < nums.size()) {
            check[nums[high]]++;
            if(check[nums[high]] > k) {
                ans = max(ans , high - low);
                while(nums[low] != nums[high]) {
                    check[nums[low]]--;
                    low++;

                }
                check[nums[low]]--;
                low++;
            }
            high++;
        }
        return max(ans , high - low);
        // unordered_map<int , int> check1;
        // low = nums.size() - 1 , high = nums.size() - 1;
        // int ans1 = 0;
        // while(low >= 0) {
        //     check1[nums[low]]++;
        //     if(check1[nums[low]] > k) {
        //         ans1 = max(ans1 , high - low);
        //         while(nums[high] != nums[low]) {
        //             check1[nums[high]]--;
        //             high--;
        //         }
        //         check1[nums[high]]--;
        //         high--;
        //     }
        //     low--;
        // }
        // ans1 = max(ans1 , high - low);
        // return max(ans , ans1);
    }
};