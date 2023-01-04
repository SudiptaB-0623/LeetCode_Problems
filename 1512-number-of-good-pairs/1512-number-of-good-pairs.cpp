class Solution 
{
public:
    int numIdenticalPairs(vector<int>& nums) 
    {
        map<unsigned int,unsigned int> mpp;
        int ans = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            auto it = mpp.find(nums[i]);
            if(it!=mpp.end())
            {
                mpp[nums[i]]++;
            }
            else
            {
                mpp[nums[i]]=1;
            }
        }
        for(auto it=mpp.begin();it!=mpp.end();it++)
        {
            //cout<<" "<<it->first<<" "<<it->second<<"\n";
            if(it->second==1)
                continue;
            else
                ans += ((it->second) * ((it->second)-1))/2;
        }
                
        return ans;
    }
};