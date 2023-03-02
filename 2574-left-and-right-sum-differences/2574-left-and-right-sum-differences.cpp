class Solution 
{
public:
    vector<int> leftRigthDifference(vector<int>& nums) 
    {
        vector<int> left = {0};
        vector<int> right, ans;
        
        int sum = 0; 
        
        for(int i=1;i<nums.size();i++)
        {
            sum = nums[i-1]+sum;
            left.push_back(sum);
        }
        
        sum = accumulate(nums.begin(),nums.end(),0);
        
        for(int i=0;i<nums.size();i++)
        {
            sum = sum - nums[i];
            right.push_back(sum);
        }
        
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back(abs(left[i]-right[i]));
        }
        
        return ans;
    }
};