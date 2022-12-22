class Solution 
{
public:
    vector<int> numberOfPairs(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        
        int count = 0;
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                count++;
                i++;
            }
        }
        
        vector<int> ans = {count};
        int a = (nums.size()-(count*2));
        ans.push_back(a);
        return ans;
    }
    
};