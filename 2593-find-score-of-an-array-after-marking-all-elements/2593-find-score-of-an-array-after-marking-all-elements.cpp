class Solution 
{
public:
    long findScore(vector<int>& nums) 
    {
        long ans = 0;
        int n = nums.size();
        vector<pair<int, int>> sorted(nums.size());

        for(int i=0; i<n; i++)
            sorted[i] = make_pair(nums[i], i);

        sort(sorted.begin(), sorted.end());
        vector<bool> marked(n, false);

        for(int i=0; i<n; i++) 
        {
            int num = sorted[i].first;
            int ind = sorted[i].second;
            if(!marked[ind]) 
            {
                ans += num;
                marked[ind] = true;
                if(ind - 1 >= 0)
                    marked[ind - 1] = true;
                
                if(ind + 1 < n)
                    marked[ind + 1] = true;
            }
        }

        return ans;
    }
};