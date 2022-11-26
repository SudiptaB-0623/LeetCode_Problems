class Solution 
{
public:
    int maxAscendingSum(vector<int>& nums) 
    {
        vector<int> check;
        int sum = nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
                sum += nums[i];
            else
            {
                check.push_back(sum);
                sum = nums[i];
            }
        }
        check.push_back(sum);
        
        sort(check.begin(),check.end());
        
        return check[check.size()-1];
    }
};