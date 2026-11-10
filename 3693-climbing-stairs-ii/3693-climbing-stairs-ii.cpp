class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n + 1 , INT_MAX);
        dp[0] = 0;
        for(int j = 1 ; j < n + 1 ; j++) {
            int i = max(0 , j - 3);
            while(i < j) {
                dp[j] = min(dp[j] , dp[i] + costs[j - 1] + (j - i) * (j - i));
                i++;
            }
        }
        return dp[n];
    }
};