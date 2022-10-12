class Solution 
{
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        vector<int> pos,neg,ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=0)
                pos.push_back(nums[i]);
            else
                neg.push_back(nums[i]);
        }
        
              
        for(int i=0,j=0,k=0;i<nums.size();i++)
        {
            if(i%2 == 0)
            {
                ans.push_back(pos[j]);
                j++;
            }
            else
            {
                ans.push_back(neg[k]);
                k++;
            }
        }
        return ans;
    }
};