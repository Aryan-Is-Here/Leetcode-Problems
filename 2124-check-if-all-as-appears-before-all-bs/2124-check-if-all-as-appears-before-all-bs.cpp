class Solution {
public:
    bool checkString(string s) {
        bool a = false, b = false;
        for(auto i : s) {
            if(i == 'b') b = true;
            if(i == 'a' && b) return false;
        }
        return true;
    }
};