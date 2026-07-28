class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        vector<int> check(26 , 0);
        for(int i = 0 ; i < n / 2 ; i++) check[s[i] - 'a']++;
        int left = 0 , right = n - 1;
        for(int i = 0 ; i < 26 ; i++) {
            while(check[i]--) {
                s[left] = i + 'a';
                s[right] = i + 'a';
                right--;
                left++;
            }
        }
        return s;
    }
};