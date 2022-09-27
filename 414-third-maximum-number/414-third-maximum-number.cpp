class Solution 
{
public:
    int thirdMax(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        
        if(nums.size()<3)
            return nums[nums.size()-1];
        
        int count=1, curr=nums[nums.size()-1];
        
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]==curr)
                continue;
            else
            {
                curr=nums[i];
                count++;
            }
            if(count==3)
                break;
        }
        if(count==3)
            return curr;
        else
            return nums[nums.size()-1];
    }
};