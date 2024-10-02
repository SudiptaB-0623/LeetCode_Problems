class Solution 
{
public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        vector<int> ans = arr;
        sort(ans.begin(), ans.end());
        
        map<int, int> mpp;
        int rank = 1;
        
        for(int i=0; i<ans.size(); i++)
        {
            if(mpp.find(ans[i]) == mpp.end())
            {
                mpp[ans[i]] = rank;
                rank++;
            }
        }
        
        for(int i=0; i<arr.size(); i++)
        {
            ans[i] = mpp[arr[i]];
        }
        
        return ans;
    }
};