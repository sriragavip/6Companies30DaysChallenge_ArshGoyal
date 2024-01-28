class Solution {
private:
    int totalLand(vector<vector<int>>& grid)
    {
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count = 0;

        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (grid[i][j] == 1 and !vis[i][j])
                {
                    queue<pair<int,int>>q;
                    vis[i][j] = 1;
                    q.push({i,j});
                    count += 1;
                    
                    while(!q.empty())
                    {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();

                        int delrow [] = {-1,0,+1,0};
                        int delcol [] = {0,1,0,-1};
                        for (int i=0;i<4;i++)
                        {
                            int nrow = row + delrow[i];
                            int ncol = col + delcol[i];
                            if (nrow >=0 and nrow < grid.size() and ncol >= 0 and ncol < grid[0].size() and !vis[nrow][ncol] and grid[nrow][ncol] == 1)
                            {
                                q.push({nrow,ncol});
                                vis[nrow][ncol] = 1;
                            }
                        }
                    }
                }
            }
        }
       
        return count;
    }
public:
    int minDays(vector<vector<int>>& grid) 
    {
        int initialLand = totalLand(grid);
        if (initialLand == 0 or initialLand >= 2)   return 0;
        
        for (int i=0;i<grid.size();i++)
        {
            for (int j=0;j<grid[0].size();j++)
            {
                if (grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    int newLand = totalLand(grid);
                    if (newLand != 1)   return 1;
                    grid[i][j] = 1;
                }
            }
        }
        
        return 2;
    }
};