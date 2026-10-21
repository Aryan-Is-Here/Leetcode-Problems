class Solution {
public:
    int minOperations(string s) {
        int k = 0 , j = 0;
        bool issorted = true;
        for(int i = 1 ; i < s.length() ; i++) {
            if(s[i] < s[k]) k = i;
            if(s[i] >= s[j]) j = i;
            if(s[i] < s[i - 1]) issorted = false;
        }
        if(s.length() == 2 && k == 1) return -1;
        else if(s.length() <= 2) return 0;
        else {
            if(issorted) return 0;
            else if(k == s.length() - 1 && j == 0) return 3;
            else if(j == s.length() - 1 || k == 0) return 1;
        }
        return 2;
    }
};