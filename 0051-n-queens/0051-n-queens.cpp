class Solution 
{
public:
    bool isSafe(int row, int col, vector<string> table, int n)
    {
        int r = row;
        int c = col;
        
        while(r>=0 && c>=0)
        {            
            if(table[r][c]=='Q')
                return false;
            r--;
            c--;
        }
        
        r = row;
        c = col;
        while(c>=0)
        {           
            if(table[r][c]=='Q')
                return false;
             c--;
        }
        
        r = row;
        c = col;
        while(r<n && c>=0)
        {            
            if(table[r][c]=='Q')
                return false;
            r++;
            c--;
        }
        return true;
    }
    void solve(int col, vector<vector<string>> &ans, vector<string> &table, int n)
    {
        if(col == n)
        {
            ans.push_back(table);
            return;
        }
        
        for(int row = 0; row<n ; row++)
        {            
            if(isSafe(row, col, table, n))
            {
                table[row][col] = 'Q';
                solve(col+1, ans, table, n);
                table[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        string row(n, '.');
        vector<string> table;
        for(int i=0;i<n;i++)
        {
            table.push_back(row);
        }
        
        solve(0, ans, table, n);
        
        return ans;
    }
};