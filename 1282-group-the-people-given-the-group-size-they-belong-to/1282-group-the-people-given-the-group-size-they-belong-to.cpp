class Solution 
{
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) 
    {
        vector<pair<int,int>> grp;
        vector<vector<int>> ans = {};
        
        for(int i=0;i<groupSizes.size();i++)
        {
            pair<int,int> a = {groupSizes[i],i};
            grp.push_back(a);
        }
        sort(grp.begin(),grp.end());
        
        for(int i=0;i<grp.size();i++)
        {
            //cout<<i<<" "<<grp[i].first<<" "<<grp[i].second<<endl;
            
            vector<int> ins;
            int k = i;
            for(int j=0;j<grp[i].first;j++,k++)
            {
                ins.push_back(grp[k].second);
            }
            ans.push_back(ins);
            i=k-1;
        }
        return ans;
    }
};