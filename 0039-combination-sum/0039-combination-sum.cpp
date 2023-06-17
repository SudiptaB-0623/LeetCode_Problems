class Solution 
{
public:
    void combination(int ind, int target, vector<int> ds, vector<vector<int>> &ans, vector<int> &arr, int size)
    {
        if(ind == size)
        {
            if(target == 0)
                ans.push_back(ds);
            return;
        }
        if(arr[ind]<=target)
        {
            ds.push_back(arr[ind]);
            combination(ind, target-arr[ind] , ds, ans , arr, size);
            ds.erase(ds.end()-1);
        }
        
        combination(ind+1, target, ds, ans , arr, size);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        int size = candidates.size();
        vector<int> ds = {};
        combination(0, target, ds, ans, candidates, size);
        
        return ans;
    }
};