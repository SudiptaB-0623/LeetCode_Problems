class Solution 
{
public:
   
    int minCostClimbingStairs(vector<int>& cost) 
    {
        vector<int> dp(cost.size(), -1);
        int ans = 0;
        dp[0] = cost[0];
        dp[1] = min(cost[1], cost[1]+cost[0]);
        cout<<dp[0]<<" "<<dp[1]<<" ";
        
        for(int i=2; i<cost.size();i++)
        {
            dp[i] =  min(dp[i-1], dp[i-2]) + cost[i];
            cout<<dp[i]<<" ";
        }
                        
        return min(dp[cost.size()-1], dp[cost.size()-2]);
    }
};