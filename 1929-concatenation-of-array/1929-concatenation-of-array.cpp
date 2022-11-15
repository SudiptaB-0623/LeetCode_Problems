class Solution 
{
public:
    vector<int> getConcatenation(vector<int>& nums) 
    {
        int count = nums.size(); 
        for(int i=0;i<count;i++)
        {
            nums.push_back(nums[i]);
        }
        return nums;
    }
};