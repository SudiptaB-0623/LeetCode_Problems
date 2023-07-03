class Solution 
{
public:
    int maxProduct(vector<int>& nums) 
    {
        int ans = INT_MIN;
        int pre = 1, suf = 1;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            pre = pre*nums[i];
            suf = suf*nums[n-1-i];
            
            ans = max(pre, max(ans,suf));
            if(pre == 0)
                pre = 1;
            if(suf == 0)
                suf = 1;
        }
        return ans;
    }
};