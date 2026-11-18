class Solution {
public:
    int minChanges(string s) {
        int n = s.length() / 2;
        int count = 0;
        for(int i = 0 ; i < n ; i++) {
            if(s[2 * i] != s[2 * i + 1]) count++;
        }
        return count;
    }
};