class Solution 
{
public:
    bool check(vector<int>& nums) 
    {
        if(nums.size()<3)
            return true;
        
        int i=1;
        for(; i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])
                break;
        }
        
        if(i>=nums.size())
            return true;
        
        for(int j=i+1; j<nums.size();j++)
        {
            if(nums[j]<nums[j-1])
                return false;
        }
        
        if(nums[nums.size()-1]<=nums[0])
            return true;
        else
            return false;
    }
};