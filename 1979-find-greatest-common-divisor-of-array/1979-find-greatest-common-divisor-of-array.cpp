class Solution 
{
public:
    int findGCD(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
                
        int ans = 1, size = nums.size();        
        
        for(int i = 2;i<=nums[0];i++)
        {
            if((nums[0]%i==0)&&(nums[size-1]%i==0))
            {
                ans = i;                
            }
        }
        
        return ans;
    }
};