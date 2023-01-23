class Solution 
{
public:
    bool isMonotonic(vector<int>& nums) 
    {            
        bool in = true;
        bool de = true;
        
        for(int i=1;i<nums.size();i++)
        {
            if(in==true && nums[i]<nums[i-1])
                in = false;
            if(de==true && nums[i]>nums[i-1])
                de = false;
            if(in==false && de==false)
                return false;
        }
        
        return true;
    }
};