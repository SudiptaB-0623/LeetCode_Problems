class Solution 
{
public:
    bool canPartition(vector<int>& nums) 
    {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++)
            sum += nums[i];
        if(sum%2==1)
            return false;
        
        sum = sum/2;
        //vector<vector<bool>> dp(n, vector<bool>(sum+1, 0));
        vector<bool> prev(sum+1, 0), cur(sum+1, 0);
        
        prev[0] = cur[0] = 1;
        if(nums[0]<=sum)
            prev[nums[0]] = 1;
        
        for(int i=1 ; i<n ; i++)
        {
            for(int target = 1; target<=sum ; target++)
            {
                bool take = 0;
                if(target>=nums[i])
                    take = prev[target-nums[i]];
                bool not_take = prev[target];
                
                cur[target] = (take || not_take);
            }
            prev = cur;
        }
        
        return prev[sum];
    }
};