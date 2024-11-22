class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) 
    {
        int n = matrix[0].size();
        int ans = 0;

        for(auto& curr : matrix) 
        {
            vector<int> flippedRow(n);
            int identicalRowCount = 0;

            for(int col = 0; col < n; col++) 
            {
                flippedRow[col] = 1 - curr[col];
            }

            for(auto& compareRow : matrix) 
            {
                if(compareRow == curr || compareRow == flippedRow) 
                {
                    identicalRowCount++;
                }
            }

            ans = max(ans, identicalRowCount);
        }

        return ans;
    }
};