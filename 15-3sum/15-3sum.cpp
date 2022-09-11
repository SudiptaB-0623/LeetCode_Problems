class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int size=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        
        for(int i=0;i<size-2 && nums[i]<=0;i++)
        {
            int j=i+1;
            int k=size-1;
                       
            //vector<vector<int>> :: iterator it;
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0)
                {
                    vector<int> v1 = {nums[i],nums[j],nums[k]};
                    
                    ans.push_back(v1);
                    j++;
                    k--;
                    while(j<size-1 && nums[j-1]==nums[j])
                        j++;
                    while(k>j+1 && nums[k+1]==nums[k])
                        k--;
                                        
                }
                else if(sum>0)
                {
                    k--;
                }
                else if(sum<0)
                {
                    j++;
                }
            }
            while(i<size-3 && nums[i]==nums[i+1])
                i++;
        }
        return ans;
    }
};