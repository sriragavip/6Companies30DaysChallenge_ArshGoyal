#include <climits>
#include <cstdint>
class Solution {
    long long getGCD(long long a, long long b) {
        if (b == 0) return a;
        return getGCD(b, a % b);
    }
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long ans = LLONG_MAX;  
        long long low = 1, high = LLONG_MAX;  

        while (low <= high) {
            long long mid = low + (high - low) / 2;  
            long long total1 = mid - mid / divisor1;
            long long total2 = mid - mid / divisor2;

            long long gcd = getGCD(divisor1, divisor2);
            long long lcm = (divisor1 / gcd) * divisor2;  

            long long temp = mid - mid / lcm;

            if (total1 >= uniqueCnt1 && total2 >= uniqueCnt2 && temp >= uniqueCnt1 + uniqueCnt2) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        return static_cast<int>(ans);
    }
};