class Solution 
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0; j<m ; j++)
            {
                if(mat[i][j] == 0)
                {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }
        
        int drow[] = {-1, 0, 0, 1};
        int dcol[] = {0, -1, 1, 0};
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();
            dist[r][c] = d;
            
            for(int i=0 ; i<4 ; i++)
            {
                int row = r + drow[i];
                int col = c + dcol[i];
                
                if(row>=0 && row<n && col>=0 && col<m && vis[row][col]!=1)
                {
                    vis[row][col] = 1;
                    q.push({{row, col}, d+1});
                }
            }
        }
        
        return dist;
    }
};