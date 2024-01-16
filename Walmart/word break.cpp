class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n, 0);
        for (int i = -1; i < n; i++) {
            if (i >= 0 && dp[i] == false) {
                continue;
            }
            for (auto word: wordDict) {
                int j = 0;
                while (j < word.length()
                    && i + 1 + j < n
                    && word[j] == s[i + 1 + j]) {
                        j++;
                }
                if (j == word.length()) {
                    dp[i + word.length()] = true;
                }
            }
        }
        return dp[n - 1];
    }
};