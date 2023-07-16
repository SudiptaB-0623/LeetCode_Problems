class Solution 
{
public:
    int buySell(int ind, int buy, int cap, int n, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if(cap == 0)
            return 0;
        if(ind == n)
            return 0;
        
        if(dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];
        
        int profit = 0;
        if(buy == 1)
        {
            int take = -prices[ind] + buySell(ind+1, 0, cap, n, prices, dp);
            int notTake = buySell(ind+1, 1, cap, n, prices, dp);
            
            profit = max(take, notTake);
        }
        else
        {
            int sell = prices[ind] + buySell(ind+1, 1, cap-1, n, prices, dp);
            int notSell = buySell(ind+1, 0, cap, n, prices, dp);
            
            profit = max(sell, notSell);
        }
        
        return dp[ind][buy][cap] = profit;
    }
    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2, vector<int>(k+1, -1)));
        
        return buySell(0, 1, k, n, prices, dp);
    }
};