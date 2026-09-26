class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string , string> mp;
        for(int i = 0 ; i < knowledge.size() ; i++) mp[knowledge[i][0]] = knowledge[i][1];
        for(int i = 0 ; i < s.length() ; i++) {
            int x = 0;
            if(s[i] == '(') {
                int j = i + 1;
                string temp = "";
                while(s[j] != ')') {
                    temp += s[j];
                    j++;
                }
                if(mp.find(temp) != mp.end()) {
                    s.erase(i , j - i + 1);
                    s.insert(i , mp[temp]);
                    x = mp[temp].size();
                    i += x - 1;
                }
                else {
                    s.erase(i , j - i + 1);
                    s.insert(i , "?");
                }
            }
        }
        return s;
    }
};