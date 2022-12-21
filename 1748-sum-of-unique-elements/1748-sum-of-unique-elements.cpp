class Solution 
{
public:
    int sumOfUnique(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<pair<int,int>> ans;
        
        int fst = nums[0];
        int count = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==fst)
            {
                count++;
            }
            else
            {
                pair<int,int> a = {fst,count};
                ans.push_back(a);
                
                count = 1;
                fst = nums[i];
            }
        }
        pair<int,int> a = {fst,count};
        ans.push_back(a);
        int sum =0;
        
        for(int i=0;i<ans.size();i++)
        {            
            if(ans[i].second==1)
                sum+=ans[i].first;
        }
        return sum;
    }
};