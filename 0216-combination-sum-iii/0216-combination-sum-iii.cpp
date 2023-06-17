class Solution 
{
public:
    void comb(int num, int target, vector<int> ds, vector<vector<int>> &ans, int k)
    {
        if(target == 0 && ds.size()==k)
            ans.push_back(ds);
        if(num>9 || ds.size()>k)
            return;
        
        for(int i=num ; i<=9 ; i++)
        {
            if(i>target)
                break;
            
            ds.push_back(i);
            comb(i+1, target-i, ds, ans, k);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<vector<int>> ans;
        vector<int> ds;
        
        comb(1, n, ds, ans, k);
        
        return ans;
    }
};