class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        bool neg = false;
        int i = 0;
        int n = s.length();
        while(i < n && s[i] == ' ') i++;
        if(s[i] == '-') {
            neg = true;
            i++;
        }
        else if(s[i] == '+') i++;
        while(i < n && s[i] >= '0' && s[i] <= '9') {
            ans = ans * 10 + (s[i] - '0');
            if(ans > INT_MAX) {
                if(neg) return INT_MIN;
                else return INT_MAX;
            }
            i++;
        }
        if(neg) return 0 - ans;
        return ans;
    }
};