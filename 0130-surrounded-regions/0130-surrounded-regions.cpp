class Solution 
{
public:
    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<int>> &vis)
    {
        vis[r][c] = 1;
        
        vector<int> drow = {0, 0, -1, 1};
        vector<int> dcol = {-1, 1, 0, 0};
        
        for(int i=0; i<4; i++)
        {
            int row = r + drow[i];
            int col = c + dcol[i];
            if(row>=0 && row<board.size() && col>=0 && col<board[0].size() && vis[row][col]==0 && board[row][col]=='O')
                dfs(row, col, board, vis);
        }
    }
    void solve(vector<vector<char>>& board) 
    {
        int n = board.size();
        int m = board[0].size();        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if((i==0 || j==0 || i==n-1 || j==m-1) && board[i][j]=='O' && vis[i][j]==0)
                    dfs(i, j, board, vis);
            }
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]=='O' && vis[i][j]==0)
                    board[i][j] = 'X';
            }
        }
    }
};