class Solution 
{
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        
        vector<int> loc(n);
        int maxi = 0;
        
        for(int i=0; i<n ; i++)
        {
            loc[i] = i;
            for(int j=0; j<i ; j++)
            {
                if(nums[i]%nums[j] == 0 && dp[j]+1>dp[i])
                {
                    dp[i] = dp[j]+1;
                    loc[i] = j;
                }
            }
            maxi = max(maxi, dp[i]);
        }
        
        vector<int> ans(maxi);
        int ind = -1;
        for(int i=0; i<n ; i++)
        {
            if(dp[i] == maxi)
            {
                ind = i;
                break;
            }
        }
        
        while(ind>=0)
        {
            maxi--;
            ans[maxi] = nums[ind];
            if(ind == loc[ind])
                break;
            ind = loc[ind];
        }
        return ans;
    }
};