class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int even = 0 ;
        int x = nums1[0];
        for(auto i : nums1) {
            if(i % 2 == 0) even++;
            x = min(x , i);
        }
        if(even == nums1.size() || !even) return true;
        if(x % 2 == 0) return false;
        return true;
    }
};