class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int ma = 0;
        for(char c : s) {
            if(c == '(') st.push(c);
            int n = st.size();
            ma = max(ma , n);
            if(c == ')') st.pop();
        }
        return ma;
    }
};