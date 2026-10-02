class Solution {
public:
    vector<string> ans;
    unordered_map<string , int>mp;
    void solve(string s , int n , int k) {
        if(k == n) {
            if(mp.find(s) == mp.end()) ans.push_back(s);
            mp[s]++;
            return;
        }
        for(int i = 0 ; i <= s.length() ; i++) {
            string x = s;
            x.insert(i , "()");
            solve(x , n , k + 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        solve("" , n , 0);
        return ans;
    }
};