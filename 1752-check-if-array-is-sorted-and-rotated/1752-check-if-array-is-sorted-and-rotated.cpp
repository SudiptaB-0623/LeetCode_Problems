class Solution 
{
public:
    bool check(vector<int>& nums) 
    {
        int pos = 0;
        for(int i=0 ; i<nums.size()-1; i++)
        {
            if(nums[i+1]<nums[i])
            {
                pos = i+1;
                break;
            }
        }
        if(pos == 0)
            return true;
        
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[(i+pos)%nums.size()] > nums[((i+pos+1)%nums.size())])
                return false;
        }
        
        return true;
    }
};