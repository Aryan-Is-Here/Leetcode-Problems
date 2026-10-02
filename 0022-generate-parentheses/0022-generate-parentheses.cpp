class Solution {
public:
    vector<string> ans;
    unordered_map<string , int>mp;
    void solve(string &s , int n , int k) {
        if(k == n) {
            if(mp.find(s) == mp.end()) ans.push_back(s);
            return;
        }
        if(mp.find(s) != mp.end()) return;
        for(int i = 0 ; i <= s.length() ; i++) {
            s.insert(i , "()");
            solve(s , n , k + 1);
            mp[s]++;
            s.erase(i , 2);
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        solve(s , n , 0);
        return ans;
    }
};