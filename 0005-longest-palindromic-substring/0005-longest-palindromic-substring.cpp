class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>>dp(n , vector<bool>(n , false));
        string str = s.substr(0 , 1);
        for(int i = 0 ; i < n ; i++) dp[i][i] = true;
        for(int i = 0 ; i < n - 1 ; i++) {
            if(s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                str = s.substr(i, 2);
            }
        }
        for(int i = n - 3 ; i >= 0 ; i--) {
            for(int j = i + 2 ; j < n ; j++) {
                if(s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if(j - i + 1 > str.length()) str = s.substr(i , j - i + 1);
                }
            }
        }
        return str;
    }
};