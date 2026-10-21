class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if(n == 1) return 1;
        int temp = 0 , i = 0;
        while(i < n) {
            int count = 1;
            if(chars[i] != chars[i + 1]) {
                chars[temp] = chars[i];
                temp++;
                i++;
                continue;
            }
            int j = i + 1;
            string x = "";
            while(j < n && chars[j] == chars[i]) {
                count++;
                j++;
            }
            x += chars[i] + to_string(count);
            int k = 0;
            while(k < x.length()) {
                chars[temp] = x[k];
                k++;
                temp++;
            }
            i = j;
        }
        return temp;
    }
};