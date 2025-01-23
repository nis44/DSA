class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX; 
        

        bool neg_sign = (dividend < 0) ^ (divisor < 0);

        long long abs_dividend = abs((long long)dividend);
        long long abs_divisor = abs((long long)divisor);
        if(abs_divisor == 1) return neg_sign ? -abs_dividend : abs_dividend;

        long long cnt = 0;
        long long temp = 0;

        while (temp + abs_divisor <= abs_dividend) {
            temp += abs_divisor;
            cnt++;
        }
        return neg_sign ? -cnt : cnt;
    }
};
