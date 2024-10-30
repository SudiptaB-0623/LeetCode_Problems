class Solution 
{
public:
    vector<int> getLongest(vector<int>& arr) 
    {
        vector<int> lisLen(arr.size(), 1);
        vector<int> lis = {arr[0]};

        for (int i=1; i<arr.size(); i++) 
        {
            int ind = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();

            if (ind == lis.size())
                lis.push_back(arr[i]);
            else 
                lis[ind] = arr[i];

            lisLen[i] = lis.size();
        }

        return lisLen;
    }

    int minimumMountainRemovals(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> lisLength = getLongest(nums);

        reverse(nums.begin(), nums.end());
        vector<int> ldsLength = getLongest(nums);
        reverse(ldsLength.begin(), ldsLength.end());

        int minRemovals = INT_MAX;
        for (int i=0; i<n; i++) 
        {
            if (lisLength[i]>1 && ldsLength[i]>1) 
                minRemovals = min(minRemovals, n - lisLength[i] - ldsLength[i] + 1);
        }

        return minRemovals;
    }
};