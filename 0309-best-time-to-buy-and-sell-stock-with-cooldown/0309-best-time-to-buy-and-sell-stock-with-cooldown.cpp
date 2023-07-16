class Solution 
{
public:
    int buySell(int ind, int buy, int n, vector<int> &prices, vector<vector<int>> &dp)
    {
        if(ind >= n)
            return 0;
        
        if(dp[ind][buy] != -1)
            return dp[ind][buy];
        
        int profit = 0;
        if(buy == 1)
        {
            int take = -prices[ind] + buySell(ind+1, 0, n, prices, dp);
            int notTake = buySell(ind+1, 1, n, prices, dp);
            
            profit = max(take, notTake);
        }
        else
        {
            int sell = prices[ind] + buySell(ind+2, 1, n, prices, dp);
            int notSell = buySell(ind+1, 0, n, prices, dp);
            
            profit = max(sell, notSell);
        }
        
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        return buySell(0, 1, n, prices, dp);
    }
};