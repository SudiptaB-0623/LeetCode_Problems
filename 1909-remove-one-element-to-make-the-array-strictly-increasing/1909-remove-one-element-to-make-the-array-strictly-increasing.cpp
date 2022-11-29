class Solution 
{
public:
    bool canBeIncreasing(vector<int>& nums) 
    {
        if(nums.size()==2)
            return true;
        
        int flag = 0;
        
        for(int i =1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
                continue;
            else
            {
                if(i==1)
                {
                    flag=1;
                    continue;
                }
                if(flag==1)
                    return false;
                
                if(flag==0 && i+1==nums.size())
                    return true;
                else
                {
                    if(i-2<0)
                    {
                        if(nums[i+1]>nums[i-1])
                        {
                            flag = 1;
                            continue;
                        }
                        else
                            return false;
                    }
                    if((nums[i]>nums[i-2])||(nums[i+1]>nums[i-1]))
                    {
                        flag=1;
                        continue;
                    }
                    else
                        return false;
                }
            }
        }
        
        return true;
    }
};