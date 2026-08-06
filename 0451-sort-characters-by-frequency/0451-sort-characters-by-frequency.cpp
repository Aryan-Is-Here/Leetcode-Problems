class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char , int> mp;
        for(auto c : s) mp[c]++;
        vector<vector<char>>bucket(n + 1);
        for(auto i : mp) bucket[i.second].push_back(i.first);
        string ans = "";
        for(int i = n ; i >= 0 ; i--) {
            for(char c : bucket[i]) {
                int x = 0;
                while(x < i) {
                    x++;
                    ans += c;
                }
            }
        }
        return ans;
    }
};