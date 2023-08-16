class Solution 
{
public:
    bool check(vector<int>& nums) 
    {
        int n = nums.size();
        
        if(n <= 2)
            return true;
        
        int i = 1;
        for( ; i<n ; i++)
        {
            if(nums[i]<nums[i-1])
                break;
        }
        
        if(i>=n)
            return true;
        
        for(int j=i+1; j<n ; j++)
        {
            if(nums[j]<nums[j-1])
                return false;
        }
        
        if(nums[n-1]<=nums[0])
            return true;
        
        return false;
    }
};