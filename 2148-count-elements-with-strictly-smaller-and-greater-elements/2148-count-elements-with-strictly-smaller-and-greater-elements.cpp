class Solution 
{
public:
    int countElements(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int ans=0;
        
        for(int i=1;i<nums.size()-1;i++)
        {
            if(nums[0]<nums[i] && nums[nums.size()-1]>nums[i])
                ans++;
        }
        
        return ans;
    }
};