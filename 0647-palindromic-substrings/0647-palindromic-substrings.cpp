class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>>dp(n , vector<bool>(n , false));
        int count = n;
        for(int i = 0 ; i < n ; i++) dp[i][i] = true;
        for(int i = 0 ; i < n - 1 ; i++) {
            if(s[i] == s[i + 1]) {
                count++;
                dp[i][i + 1] = true;
            }
        }
        for(int i = n - 3 ; i >= 0 ; i--) {
            for(int j = i + 2 ; j < n ; j++) {
                if(s[i] == s[j] && dp[i + 1][j - 1]) {
                    count++;
                    dp[i][j] = true;
                }
            }
        }
        return count;
    }
};