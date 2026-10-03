class Solution {
public:
    int longestValidParentheses(string s) {
        if(!s.length()) return 0;
        stack<int> st;
        for(int i = 0 ; i < s.length() ; i++) {
            if(!st.empty() && s[i] == ')' && s[st.top()] == '(') st.pop();
            else st.push(i);
        }
        if(st.empty()) return s.length();
        int y = st.top();
        int ans = s.length() - y - 1;
        while(!st.empty()) {
            int x = y;
            st.pop();
            if(st.empty()) y = -1;
            else y = st.top();
            ans = max(ans , x - y - 1); 
        }
        return ans;
    }
};