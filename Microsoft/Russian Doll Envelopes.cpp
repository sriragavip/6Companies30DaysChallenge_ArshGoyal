class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        for(int i=0; i<envelopes.size(); i++){
            envelopes[i][1]=(-1)*envelopes[i][1];
        }
        sort(envelopes.begin(), envelopes.end());
        vector<int>dp;
        for(int i=0; i<envelopes.size(); i++){
            auto it=lower_bound(dp.begin(), dp.end(), envelopes[i][1]*(-1))-dp.begin();
            if(it==dp.size())dp.push_back(envelopes[i][1]);
            dp[it]=envelopes[i][1]*(-1);
        }
        return dp.size();
    }
};