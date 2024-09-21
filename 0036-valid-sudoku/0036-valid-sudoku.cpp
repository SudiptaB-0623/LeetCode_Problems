class Solution 
{
public:
    bool isSafe(vector<vector<char>> &board, int m, int n, char c)
    {
        for(int i=0; i<=8; i++)
        {
            if(board[i][n] == c && i!=m)
                return false;
            
            if(board[m][i] == c && i!=n)
                return false;
            
            int row = 3*(m/3) + i/3;
            int col = 3*(n/3) + i%3;
            
            if(board[row][col] == c && (row!=m && col!=n))
                return false;
        }
        
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        for(int i=0; i<=8; i++)
        {
            for(int j=0; j<=8; j++)
            {
                if(board[i][j] != '.')
                {
                    if(isSafe(board, i, j, board[i][j]) != true)
                        return false;
                }
            }
        }
        
        return true;
    }
};