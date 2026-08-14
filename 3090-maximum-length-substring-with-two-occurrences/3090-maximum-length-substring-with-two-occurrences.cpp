class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 2;
        unordered_map<char , int> mp;
        int low = 0 , high  = 0;
        while(high < s.length()) {
            mp[s[high]]++;
            if(mp[s[high]] > 2) {
                ans = max(ans , high - low);
                while(s[low] != s[high]) {
                    mp[s[low]]--;
                    low++;
                }
                mp[s[low]]--;
                low++;
            }
            high++;
        }
        ans = max(ans , high - low);
        return ans;
    }
};