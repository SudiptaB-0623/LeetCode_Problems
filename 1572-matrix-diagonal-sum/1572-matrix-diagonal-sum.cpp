class Solution 
{
public:
    int diagonalSum(vector<vector<int>>& mat) 
    {
        int sum=0;
        for(int i=0,j=mat.size()-1;i<mat.size();i++,j--)
        {
            sum= sum + mat[i][i] + mat[i][j];
        }
        
        if(mat.size()%2 == 1)
        {
            sum = sum - mat[mat.size()/2][mat.size()/2];
        }
                                             
        return sum;
    }
};