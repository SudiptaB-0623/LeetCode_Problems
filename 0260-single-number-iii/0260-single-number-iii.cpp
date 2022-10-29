class Solution 
{
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        if(nums.size()==2)
            return nums;
        
        sort(nums.begin(),nums.end());
                
        vector<int> ans;
        
        int key = nums[0];
        int flag = 1;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==key)
            {
                flag++;
            }
            else
            {
                if(flag==2)
                {
                    key=nums[i];
                    flag = 1;
                }
                else
                {
                    ans.push_back(nums[i-1]);
                    if(ans.size()==2)
                        return ans;
                    key=nums[i];
                    flag = 1;
                }
            }
        }
        
        ans.push_back(nums[nums.size()-1]);
        return ans;
    }
};