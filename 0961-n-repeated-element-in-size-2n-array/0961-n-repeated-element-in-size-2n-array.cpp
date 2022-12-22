class Solution 
{
public:
    int repeatedNTimes(vector<int>& nums) 
    {
        int t = nums.size()/2;
        sort(nums.begin(),nums.end());
        
        int tgt = nums[0], count = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            {
                count++;
            }
            else
            {
                tgt = nums[i];
                count = 1;
            }
            if(count==t)
                return tgt;
        }
        return 0;
    }
};