class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if(nums.size()<=2)
            return nums.size();
        
        vector<int> :: iterator it;
        
        int key = nums[0];
        int flag = 1;
        
        for(int i=1;i<nums.size();i++)
        {            
             if(nums[i]==key)
             {                 
                 if(flag<2)
                     flag++;
                 else
                 {
                     it=nums.begin() + (i-1);
                     nums.erase(it);
                     i--;
                 }
             }
            else
            {
                key=nums[i];
                flag=1;
            }
        }
        
        return nums.size();
    }
};