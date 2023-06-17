class Solution 
{
public:
    void combination(int ind, int target, vector<int> ds, vector<vector<int>> &ans, vector<int> &arr, int n)
    {
        if(target == 0)
            ans.push_back(ds);
        if(ind == n)
            return;
        //cout<<ind<<" "<<target<<endl;
        for(int i=ind;i<=n-1;i++)
        {
            if(arr[i]>target)
                break;
            if(i>ind && arr[i]==arr[i-1])
                continue;
            
            ds.push_back(arr[i]);
            combination(i+1, target-arr[i], ds, ans, arr, n);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        for(int i=0; i<candidates.size();i++)
            cout<<candidates[i]<<" ";
        cout<<endl;
        vector<vector<int>> ans;
        vector<int> ds = {};
        int n = candidates.size();
        
        combination(0, target, ds, ans, candidates, n);
        
        return ans;
    }
};