class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        
        int key=nums[0];
        int flag=1;
        
        for(int i = 1;i<nums.size();i++)
        {
            
            if(nums[i]==key)
            {    
                
                flag++;
                i++;                
            }
            else
            {
                if(flag>=2)
                {
                    key=nums[i];
                    flag=1;
                }
                else
                    return nums[i-1];
            }
        }
        return nums[nums.size()-1];
    }
};