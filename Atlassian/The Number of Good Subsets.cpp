const int mod = 1e9 + 7;
const vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

class Solution {
public:
    vector<int> mult; // x->mult of x in nums w/o 1, square factor
    vector<int> bMask; // x->bitMask for factorization of x
    int ones = 0; // the mult of 1 in nums
    int maxMask = 0;

    void print(vector<int>& mult) {
        int n = mult.size();
        for (int i = 2; i < n; i++) {
            if (mult[i] != 0) {
                cout << i << " m=" << mult[i] << ", ";
            }
        }
        cout << endl;
    }

    int factorization(int x) {
        int bMask = 0;
        for (int j = 0; j < 10; j++) {
            if (x % prime[j] == 0) {
                bMask |= (1 << j);
            }
        }
        return bMask;
    }

    void remove_bad_x_build_mult(vector<int>& nums) {
        mult.assign(31, 0);
        bMask.assign(31, 0);
        for (int x : nums) {
            if (x == 1) {
                ones++;
                continue;
            }
            if (x % 4 == 0 || x % 9 == 0 || x % 25 == 0) {
                continue;
            }
            mult[x]++;
            if (bMask[x] == 0) {
                int mask = factorization(x);
                bMask[x] = mask;
                maxMask |= mask;
            }
        }
    //    print(bMask);
    }

    // Least significant bit first algorithm
    long long modPow(long long x, int exp, int mod) {
        if (x == 0) return 0;
        if (exp == 0) return 1;
        long long y = modPow(x * x % mod, exp >> 1, mod);
        return (exp % 2 == 0) ? y : y * x % mod;
    }

    int numberOfGoodSubsets(vector<int>& nums) {
        int res = 0;
        vector<int> dp(1 << 10, 0), incr;
        dp[0] = 1; // everything is absent

        remove_bad_x_build_mult(nums);

        for (int x = 2; x < 31; x++) { // there are m times x in nums
            // find current mask
            int m = mult[x];
            if (m == 0) continue;
            int x_mask = bMask[x];

            // updates
            incr.assign(1 << 10, 0);
            for (int mask = 0; mask <= (maxMask); mask++) {
                if ((x_mask & mask) == 0) { // gcd=1
                    // index = mask for product
                    incr[mask | x_mask] = (1LL * dp[mask] * m) % mod;
                }
            }

            // add to dp
            for (int i = 0; i <= (maxMask); i++) {
                dp[i] = (dp[i] + incr[i]) % mod;
            }
        }

        // summation
        for (int i = 1; i <= (maxMask); i++) {
            res = (res + dp[i]) % mod;
        }

        // deal with ones using LSBF based on binary expression for ones
        res = (1LL * res * modPow(2LL, ones, mod)) % mod;

        return res;
    }
};