class Solution 
{
public:
    void sub_seq(vector<int> a, vector<int> b, vector<vector<int>> &ans)
    {
        ans.push_back(a);
        if(b.size()==0)
            return;
        
        for(int i=0;i<b.size();i++)
        {
            vector<int> temp, temp2;
            temp2.insert(temp2.end(), a.begin(), a.end());
            temp2.insert(temp2.end(), b.begin()+i, b.begin()+i+1);
            
            temp.insert(temp.begin(), b.begin()+i+1, b.end());
            sub_seq(temp2, temp, ans);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        
        for(int i=0;i<nums.size();i++)
        {
            vector<int> temp , temp2;
            temp.insert(temp.begin(), nums.begin()+i+1,nums.end());
            temp2.push_back(nums[i]);
            
            sub_seq(temp2, temp, ans);
        }
        ans.push_back({});
        return ans;
    }
};