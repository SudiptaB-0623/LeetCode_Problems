class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        if(nums.size()==1)
            return nums[0];
        sort(nums.begin(),nums.end());
        int size=nums.size()/2;
        
        int t=1;
        
        for(int i=1;i<nums.size();i++)
        {
            
            if(nums[i]==nums[i-1])
            {
                t++;
            }
            else
                t=1;
            
            if(t>size)
                return nums[i];
        }
        return 0;
        
    }
};