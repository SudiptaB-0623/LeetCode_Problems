class Solution 
{
public:
    int smallestRangeI(vector<int>& nums, int k) 
    {
        int mx = *max_element(nums.begin(),nums.end());
        int mn = *min_element(nums.begin(),nums.end());
        
        if(mx-mn-k-k>0)
            return mx-mn-k-k;
        else
            return 0;
    }
};