class Solution 
{
public:
    bool kLengthApart(vector<int>& nums, int k) 
    {
        if(nums.size()==1)
            return true;
        
        int count = 0, flag = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                if(count<k && flag!=0)
                    return false;
                else
                {
                    count = 0;
                    flag++;
                }
            }
            else
                count++;
        }
        
        return true;
    }
};