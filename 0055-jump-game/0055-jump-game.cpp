class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        if(nums.size() == 1)
            return true;
        if(nums[0] == 0)
            return false;
        int d=0;
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==0 && d==i)
            {
                return false;
            }
            d=max(d,nums[i]+i);
            
        }
        return true;
    }
};