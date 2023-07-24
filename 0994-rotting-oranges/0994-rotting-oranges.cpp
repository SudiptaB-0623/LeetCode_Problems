class Solution 
{
public:
    
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int time = 0, ans = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int drow[] = {-1, 0, 0, 1};
        int dcol[] = {0, -1, 1, 0};
        queue<pair<pair<int, int>, int>> q;
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(grid[i][j] == 2)
                    q.push({{i, j}, 0});
            }
        }       
        
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            time = q.front().second;
            ans = max(ans, time);
            
            q.pop();
            
            for(int i=0 ; i<4 ; i++)
            {
                int currRow = r+drow[i];
                int currCol = c+dcol[i];
                
                if(currRow>=0 && currRow<n && currCol>=0 && currCol<m && vis[currRow][currCol]==0 && grid[currRow][currCol]!=0 && grid[currRow][currCol]!=2)
                {
                    q.push({{currRow, currCol}, time+1});
                    vis[currRow][currCol]=1;
                    grid[currRow][currCol]=2;
                }
            }
        }
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        
        return ans;
    }
};