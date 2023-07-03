class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int mini = prices[0];
        int profit = 0;
        if(prices.size()<=1)
            return profit;
        
        for(int i = 0;i<prices.size(); i++)
        {
            int temp = prices[i] - mini;
            profit = max(profit, temp);
            mini = min(mini, prices[i]);
        }
        
        return profit;
    }
};