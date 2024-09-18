class Solution 
{
public:
    void recur(int ind, int size, string &ans, string ds, unordered_set<string> st)
    {
        if(ind >= size)
        {
            if(st.find(ds) == st.end())
                ans = ds;
            return;
        }
        
        ds = ds + '0';
        recur(ind+1, size, ans, ds, st);
        
        if(ans.size()>0)
            return;
        
        ds[ind] = '1';
        recur(ind+1, size, ans, ds, st);
    }
    string findDifferentBinaryString(vector<string>& nums) 
    {
        string ans = "";
        unordered_set<string> st;
        for(int i=0; i<nums.size(); i++)
            st.insert(nums[i]);
        
        recur(0, nums.size(), ans, "", st);
        
        return ans;
    }
};