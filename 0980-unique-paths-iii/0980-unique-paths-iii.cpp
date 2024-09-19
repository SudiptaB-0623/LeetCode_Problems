class Solution 
{
public:
    void recur(int i, int j, vector<vector<int>> grid, vector<vector<int>> vis, int zero, int &ans)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==-1 || vis[i][j]==1)
            return;
        
        if(grid[i][j]==2 && zero<=0)
            ans += 1;
        
        vis[i][j] = 1;
        
        if(grid[i][j] == 0)
            zero -= 1;
        
        recur(i-1, j, grid, vis, zero, ans);
        recur(i+1, j, grid, vis, zero, ans);
        recur(i, j-1, grid, vis, zero, ans);
        recur(i, j+1, grid, vis, zero, ans);
        
        vis[i][j] = 0;        
    }
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        int zero = 0;
        int row=0, col=0;
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        int ans = 0;
        
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]==1)
                {
                    row = i;
                    col = j;
                }
                if(grid[i][j]==0)
                    zero++;
            }
        }
        
        recur(row, col, grid, vis, zero, ans);
        
        return ans;
    }
};