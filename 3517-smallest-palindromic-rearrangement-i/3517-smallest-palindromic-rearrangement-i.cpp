class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        if(n == 1) return s;
        int half = n / 2 - 1;
        string ans = s.substr(0 , n / 2);
        sort(ans.begin() , ans.end());
        if(n % 2) ans += s[n/2];
        while(half >= 0) {
            ans += ans[half];
            half--;
        }
        return ans;
    }
};