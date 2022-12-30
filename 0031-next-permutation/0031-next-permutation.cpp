class Solution 
{
public:
    void nextPermutation(vector<int>& nums) 
    {
        int ind = -1, ind2 = -1;
        
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                ind = i;
                break;
            }
        }
        if(ind!=-1)
        {
            for(int i=nums.size()-1;i>=ind;i--)
            {
                if(nums[i]>nums[ind])
                {
                    ind2=i;
                    break;
                }
            }
            swap(nums[ind],nums[ind2]);
            reverse(nums.begin()+(ind+1),nums.end());
        }
        else
            reverse(nums.begin(),nums.end());
    }
};