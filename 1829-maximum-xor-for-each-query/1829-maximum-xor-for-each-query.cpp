class Solution 
{
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) 
    {
        int n = nums.size();
        int xorProduct = 0;
        vector<int> ans(n);
        
        for(int i=0; i<n; i++) 
            xorProduct = xorProduct ^ nums[i];
              
        int mask = (1 << maximumBit) - 1;

        for(int i=0; i<n; i++)
        {
            ans[i] = xorProduct ^ mask;
            xorProduct = xorProduct ^ nums[n-1-i];
        }

        return ans;
    }
};