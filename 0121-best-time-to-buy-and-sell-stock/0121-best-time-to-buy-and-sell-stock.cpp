class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_num = 0 , ans = 0;
        for(int i = prices.size() - 1 ; i >= 0 ; i--) {
            max_num = max(max_num , prices[i]);
            prices[i] = max_num - prices[i];
            ans = max(ans , prices[i]);
        }
        return ans;
    }
};