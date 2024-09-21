class Solution 
{
public:
    bool isSafe(vector<vector<char>> &board, int m, int n, char c)
    {
        for(int i=0; i<=8; i++)
        {
            if(board[i][n] == c)
                return false;
            
            if(board[m][i] == c)
                return false;
            
            int row = 3*(m/3) + i/3;
            int col = 3*(n/3) + i%3;
            
            if(board[row][col] == c)
                return false;
        }
        
        return true;
    }
    bool solve(vector<vector<char>> &board)
    {
        for(int i=0; i<=8; i++)
        {
            for(int j=0; j<=8; j++)
            {
                if(board[i][j]=='.')
                {
                    for(char c='1'; c<='9'; c++)
                    {
                        if(isSafe(board, i, j, c))
                        {
                            board[i][j] = c;
                            if(solve(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) 
    {
        solve(board);
    }
};