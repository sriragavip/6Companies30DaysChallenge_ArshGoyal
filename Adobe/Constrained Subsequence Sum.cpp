class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size(), ans = INT_MIN;
        
        vector<int> dp(n);
        deque<int> sums;
        
        for (int i = 0; i < n; i++) {
            if (sums.front() == i - k - 1) sums.pop_front();
            dp[i] = max(nums[i] + (sums.empty() ? 0 : dp[sums.front()]), nums[i]);
            ans = max(ans, dp[i]);
            while (!sums.empty() && dp[sums.back()] <= dp[i]) sums.pop_back();
            sums.push_back(i);
        }
        
        return ans;
    }
};