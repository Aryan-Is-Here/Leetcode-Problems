class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length() , m = haystack.length();
        vector<int>lps(n , 0);
        int i = 1 , len = 0;
        while(i < n) {
            if(needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if(len > 0) len = lps[len - 1];
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        int j = 0;
        i = 0;
        while(i < m) {
            if(haystack[i] != needle[j]) {
                if(j > 0) j = lps[j - 1];
                else i++;
            }
            else {
                i++;
                j++;
            }
            if(j == n) return i - n;
        }
        return -1;
    }
};