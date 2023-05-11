class Solution 
{
private:
    int neighb(vector<vector<int>>& board, int i, int j)
    {
        int ans = 0;
        ans += getLive(board, i-1, j-1);
        ans += getLive(board, i-1, j);
        ans += getLive(board, i-1, j+1); 
        ans += getLive(board, i, j-1); 
         
        ans += getLive(board, i, j+1); 
        ans += getLive(board, i+1, j-1);
        ans += getLive(board, i+1, j);
        ans += getLive(board, i+1, j+1);
        return ans;
    }
    int getLive(vector<vector<int>>& board, int i, int j)
    {
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return 0;
        else
            return board[i][j];
    }
public:
    void gameOfLife(vector<vector<int>>& board) 
    {
        vector<vector<int>> init = board;
        int r = board.size();
        int c = board[0].size();
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                int n =  neighb(init,i,j);
                int box = init[i][j];
                if(box == 1)
                { 
                    if(n < 2) 
                        box = 0;
                    else if(n == 2 || n == 3)   
                        box = 1;
                    else if(n > 3) 
                        box = 0;
                } 
                else 
                { 
                    if(n == 3) 
                        box =1;
                }
                if(init[i][j] != box) 
                    board[i][j] = box;
            }    
        }        
    }
};