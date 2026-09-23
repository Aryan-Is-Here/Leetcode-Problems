class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        stack<int> st;
        st.push(0);
        for(char ch : s) {
            if(ch == '(') st.push(0);
            else {
                int x = st.top();
                st.pop();
                if(x == 0) x = 1;
                else x *= 2;
                st.top() += x;
            }
        }
        return st.top();
    }
};