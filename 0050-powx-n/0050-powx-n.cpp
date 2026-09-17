class Solution {
public:
    double helper(double x , int n) {
        if(n == 0) return 1.0;
        if(n == 1) return x;
        if(n % 2 == 0) return helper(x * x , n / 2);
        return x * helper(x , n - 1);
    }
    double myPow(double x, int n) {
        if(n == INT_MIN && abs(x) != 1.0) return 0.0; 
        if(n < 0) {
            x = 1.0 / x;
            if(n == INT_MIN) n = 0;
            else n = -n;
        }
        return helper(x , n);
    }
};