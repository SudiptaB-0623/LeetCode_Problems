class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
    {
        int size=nums.size();
        int ind;
        
        for(int i=0;i<size;i++)
        {
                nums[nums[i]%size]=nums[nums[i]%size]+size;
                
                if(nums[nums[i]%size]>=(size*2)+1)
                {
                    
                    ind=i;
                    break;
                }
        }
        for(int i=0;i<size;i++)
        {
            nums[i]=nums[i]%size;
        }
        
        return nums[ind];
        
    }
};