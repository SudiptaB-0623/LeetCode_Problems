class Solution 
{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        if(nums.size()==0)
            return nums;
        
        vector<int> ans;
        
        sort(nums.begin(),nums.end());
                
        if(nums[0]!=1)
            ans.push_back(1);
                
        for(int i=0,j=2;j<=nums.size();i++)
        {
            if(i<=nums.size()-1)
            {
                if(i>0)
                    if(nums[i]==nums[i-1])
                    {
                        j=nums[i]+1;
                        continue;
                    }
                if(nums[i]>j)
                {
                    
                    while(j!=nums[i])
                    {
                        ans.push_back(j);
                        j++;
                    }
                    j++;
                    //continue;
                }
                if(nums[i]==j)
                    j++;
                
            }
            else
            {
                ans.push_back(j);
                j++;
            }
        }
        
        return ans;
    }
};