class Solution 
{
public:
    bool check(vector<int>& nums) 
    {
        int ind = 0;
        int n = nums.size();
        for(int i=1; i<n; i++)
        {
            if(nums[i]<nums[i-1])
            {
                ind = i;
                break;
            }
        }
        if(ind == 0)
            return true;
        
        for(int i=0, j=ind ; i<n-1; i++, j++)
        {
            if(nums[j%n]>nums[(j+1)%n])
                return false;
        }
        return true;
    }
};