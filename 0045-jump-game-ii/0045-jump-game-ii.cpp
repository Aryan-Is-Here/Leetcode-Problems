class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> check (n , 0);
        check[0] = 1;
        int i = 0 ;
        while(check[n - 1] == 0) {
            int x = 0 , j = i + 1;
            if(check[i]) x = nums[i];
            while(x-- && j < n) {
                if(check[j] == 0) check[j] = check[i] + 1;
                j++;
            }
            i++;
        }
        return check[n - 1] - 1;
    }
};