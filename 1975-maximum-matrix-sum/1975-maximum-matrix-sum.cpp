class Solution 
{
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) 
    {
        long long ans = 0;
        int minAbsVal = INT_MAX;
        int neg = 0;

        for(auto& row : matrix) 
        {
            for(int val : row) 
            {
                ans += abs(val);
                if(val < 0) 
                    neg++;
                minAbsVal = min(minAbsVal, abs(val));
            }
        }

        if(neg % 2 != 0)
            ans -= 2 * minAbsVal;

        return ans;
    }
};