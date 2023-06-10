class Solution 
{
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int missing = 0, repeat = 0, j=1;
        for(int i=0;i<nums.size();i++)
        {
            cout<<nums[i]<<" ";
        }
        
        for(int i=0; i<nums.size(); i++, j++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                repeat = nums[i];
                j--;
                cout<<j<<" ";
                continue;
            }
            
            if(missing == 0 && nums[i]!=j)
                missing = j;            
        }
        if(missing==0)
            missing=nums.size();
        return {repeat,missing};
    }
};