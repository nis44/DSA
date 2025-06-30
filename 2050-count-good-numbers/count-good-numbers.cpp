#define ll long long

class Solution {
public:
    int countGoodNumbers(long long n) {
        ll count_of_4s = n / 2;
        ll count_of_5s = n - count_of_4s;
        ll ans = (power(5, count_of_5s) * power(4, count_of_4s)) % p;
        return (int)ans;
    }

    ll power(long long x, long long y) {
        ll ans = 1;
        x = x % p;

        while (y > 0) {
            if (y % 2 == 1)
                ans = (ans * x) % p;

            x = (x * x) % p;
            y /= 2;
        }

        return ans;
    }

    int p = 1e9 + 7;
};