class Solution {
public:
    long long minimumCost(string s, string t, vector<char>& o, vector<char>& c, vector<int>& cost) {
    if (s.size() != t.size()) return -1;

    vector<vector<long long>> dis(26, vector<long long>(26, 1e12));
   dis[0][0]=0;
      for(int i=0;i<26;i++) dis[i][i]=0;
    int n = o.size();
    for (int i = 0; i < n; ++i) {
        dis[o[i] - 'a'][c[i] - 'a'] = min(dis[o[i] - 'a'][c[i] - 'a'], static_cast<long long>(cost[i]));
    }

    for (int k = 0; k < 26; ++k) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (dis[i][k] == 1e12 || dis[k][j] == 1e12) continue;
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    long long ans = 0;
    int m = s.size();

    for (int i = 0; i < m; ++i) {
        long long diff = dis[s[i] - 'a'][t[i] - 'a'];
      
        if (diff == 1e12) {
            return -1; 
        }
        ans += diff;
    }

    return ans;
} 
};