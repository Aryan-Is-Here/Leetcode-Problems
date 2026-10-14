class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum < 1 || sum > num * 9) return "";
        string ans = "";
        while(num > 0) {
            if(sum < 9) {
                ans += to_string(sum);
                sum = 0;
            }
            else {
                ans += '9';
                sum -= 9;
            }
            num--;
        }
        return ans;

    }
};