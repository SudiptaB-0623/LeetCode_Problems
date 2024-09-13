class Solution 
{
public:
    void comb(int ind, int n, int k, vector<vector<int>> &ans, vector<int> ds)
    {
        if(k==0)
        {
            ans.push_back(ds);
            return;
        }
        if(ind>n)
            return;
        for(int i=ind; i<=n ; i++)
        {
            ds.push_back(i);
            comb(i+1, n, k-1, ans, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> ans;
        vector<int> ds;
        
        comb(1, n, k, ans, ds);
        
        return ans;
    }
};