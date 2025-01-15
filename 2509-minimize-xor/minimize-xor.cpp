class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int res = 0;
        int t_bit = __builtin_popcount(num2);
        for(int i = 31; i >= 0 && t_bit > 0; i--) {
            if(num1 & (1 << i)) {
                res |= (1<<i);
                t_bit--;
            }
        }

        for(int i = 0; i < 32 && t_bit > 0; i++) {
            if(!(res & (1 << i))) {
                res |= (1 << i);
                t_bit--;
            }
        }

        return res;
    }
};