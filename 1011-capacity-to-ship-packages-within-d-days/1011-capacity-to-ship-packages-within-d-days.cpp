class Solution 
{
public:
    bool feasible(vector<int>& weights, int count, int days) 
    {
        int daysReq = 1, curr = 0;
        for(int weight : weights) 
        {
            curr += weight;
            if (curr > count) 
            {
                daysReq++;
                curr = weight;
            }
        }

        return daysReq <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) 
    {
        int total = 0, maxi = 0;
        for(int weight : weights) 
        {
            total += weight;
            maxi = max(maxi, weight);
        }

        int left = maxi, right = total;

        while(left < right) 
        {
            int mid = (left + right) / 2;
            
            if (feasible(weights, mid, days))
                right = mid;
            else 
                left = mid + 1;
        }
        return left;
    }
};