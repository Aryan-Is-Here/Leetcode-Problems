class Solution {
public:
    bool canAliceWin(int n) {
        int x = 10;
        bool turn = true;
        while(x > 0 && n >= 0) {
            if(n >= x) turn = !turn;
            if(n < x && turn) return false;
            n -= x;
            x--;
        }
        return true;
    }
};