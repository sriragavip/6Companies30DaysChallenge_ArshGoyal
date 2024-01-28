class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        vector<vector<int>> floyd(n, vector<int>(n, 1e9));
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            floyd[u][v] = wt;
            floyd[v][u] = wt;
        }

        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
                    if(i == j) floyd[i][j] = 0;
                }
            }
        }

        int mn = 1e9;
        int ans = -1;

        for(int i = 0; i < n; i++)
        {
            int count = 0;
            for(int j = 0; j < n; j++)
            {
                if(floyd[i][j] <= distanceThreshold)
                {
                    count++;
                }
            }

            if(count < mn)
            {
                mn = count;
                ans = i;
            }
            else if(count == mn)
            {
                ans = i;
            }
        }
        return ans;
    }
};