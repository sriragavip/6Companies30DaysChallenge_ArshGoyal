constexpr int mod = (int)1e9 + 7;
class Solution {
public:
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(1 << n, vector<int>(n));
        for(int i = 0 ; i < n ; i++)    dp[1 << i][i] = 1;
        
        for(int mask = 1 ; mask < (1 << n) ; mask++) {
            for(int i = 0 ; i < n ; i++) {
                if(mask >> i & 1 ^ 1)  continue;
                for(int j = 0 ; j < n ; j++) {
                    if(mask >> j & 1)  continue;
                    if(nums[j] % nums[i] == 0 || nums[i] % nums[j] == 0) {
                        dp[mask | 1 << j][j] += dp[mask][i];
                        if(dp[mask | 1 << j][j] >= mod)
                            dp[mask | 1 << j][j] -= mod;
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            ans += dp.back()[i];
            if(ans >= mod)  ans -= mod;
        }
        return ans;
    }
};