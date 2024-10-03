class Solution 
{
public:
    int minSubarray(vector<int>& nums, int p) 
    {
        int total = 0;
        for(int num : nums)
            total = (total + num)%p;
        
        if(total % p == 0)
            return 0;
        
        int target = total % p;
        int currSum = 0;
        int minLen = nums.size();
        map<int, int> mpp;
        mpp[0] = -1;
        
        for(int i=0; i<nums.size(); i++)
        {
            currSum = (currSum+nums[i])%p;
            
            int needed = (currSum-target+p)%p;
            
            if(mpp.find(needed) != mpp.end())
                minLen = min(minLen, i-mpp[needed]);
            
            mpp[currSum] = i;
        }
        
        return minLen==nums.size() ? -1 : minLen;
    }
};