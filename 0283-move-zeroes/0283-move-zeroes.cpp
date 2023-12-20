class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
        int count = 0;
        int ind = 0;
        for(int i=0 ; i<nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                count++;
            }
            else
            {
                nums[ind] = nums[i];
                ind++;
            }
        }
        for(int i=nums.size()-1; count>0; count--, i--)
        {
            nums[i] = 0;
        }
    }
};