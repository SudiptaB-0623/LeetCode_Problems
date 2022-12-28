class Solution 
{
public:
    vector<int> findLonely(vector<int>& nums) 
    {
        
        vector<int> ans;
        
        map<int,int> mpp;
        map<int,int> :: iterator it,itr1,itr2;
        
        sort(nums.begin(),nums.end());
        
        mpp[nums[0]]=1;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            {
                it = mpp.find(nums[i]);
                it->second++;
            }
            else
            {
                mpp[nums[i]]=1;
            }
        }
        
        for(it = mpp.begin();it!=mpp.end();it++)
        {
            if(it->second==1)
            {
                //cout<<(it->first)-1<<endl;
                itr1 = mpp.find((it->first)-1);
                itr2 = mpp.find((it->first)+1);
                
                if((itr1==mpp.end())&&(itr2==mpp.end()))
                    ans.push_back(it->first);
            }
        }
        
        return ans;
    }
};