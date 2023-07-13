class Solution 
{
public:
    int minDistance(string text1, string text2) 
    {
        int ind1 = text1.size();
        int ind2 = text2.size();
        vector<vector<int>> dp(ind1+1, vector<int>(ind2+1, 0)); 
                
        for(int i=1 ; i<=ind1 ; i++)
        {
            for(int j=1 ; j<=ind2 ; j++)
            {
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        
        return (ind1+ind2)-(dp[ind1][ind2]*2);
    }
};