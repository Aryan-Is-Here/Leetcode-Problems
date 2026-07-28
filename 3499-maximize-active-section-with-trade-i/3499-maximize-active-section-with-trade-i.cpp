class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        // stack<int>st1;
        // stack<int>st2;
        // int n = s.length();
        // int count = 0;
        // for(auto c : s) if(c == '1') count++;
        // vector<int>right(n , n);
        // vector<int>left(n , -1);
        // for(int i = n - 1 ; i >= 0 ; i--) {
        //     while(!st1.empty() && s[st1.top()] == '0') st1.pop();
        //     if(i < n - 1 && (s[i] == '1' && s[i + 1] == '1')) right[i] = right[i + 1];
        //     else if(!st1.empty()) right[i] = st1.top();
        //     st1.push(i);
        // }
        // for(int i = 0 ; i < n ; i++) {
        //     while(!st2.empty() && s[st2.top()] == '0') st2.pop();
        //     if(i > 0 && (s[i] == '1' && s[i - 1] == '1')) left[i] = left[i + 1];
        //     else if(!st2.empty()) left[i] = st2.top();
        //     st1.push(i);
        // }
        int n = s.length();
        int c1 = 0;
        for(auto c : s) if(c == '1') c1++;
        if(n <= 2) return c1;
        vector<int>zeroes;
        int count = 0;
        for(int i = 0 ; i < n ; i++) {
            if(s[i] == '0') count++;
            else{
                if(count > 0) {
                    zeroes.push_back(count);
                    count = 0;
                }
            }
        }
        if(count > 0) zeroes.push_back(count);
        if(zeroes.size() <= 1) return c1;
        int c2 = 0;
        for(int i = 0 ; i < zeroes.size() - 1 ; i++) c2 = max(c2 , zeroes[i] + zeroes[i + 1]);
        return c1 + c2;

    }
};