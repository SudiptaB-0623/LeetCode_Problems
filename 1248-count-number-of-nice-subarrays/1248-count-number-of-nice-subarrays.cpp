class Solution 
{
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int ans = 0;
        
        vector<int> temp;
        for(int i=0 ; i<n ; i++)
        {
            temp.push_back(nums[i]%2);
        }
        
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int sum = 0;
        for(int i=0 ; i<n ; i++)
        {
            sum += temp[i];
            if(mpp.find(sum-k) != mpp.end())
                ans += mpp[sum-k];
            
            mpp[sum]++;
        }
        
        return ans;
    }
};