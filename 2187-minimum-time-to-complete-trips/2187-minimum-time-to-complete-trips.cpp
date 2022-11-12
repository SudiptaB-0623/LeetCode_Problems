class Solution 
{
public:
    long long minimumTime(vector<int>& time, int totalTrips) 
    {        
        long long high = (*min_element(time.begin(),time.end())) * (long long)totalTrips;
        long long low = 1;
        
        while(low<high)
        {
            long long mid = low + ((high-low)/2);
            long long sum = 0;
            for(int i=0;i<time.size();i++)
            {
                sum = sum + (mid/time[i]);
            }
                        
            if(sum>=totalTrips)
            {
                high = mid;
            }
            else
            {
                low = mid +1;
            }
        }
        return low;
    }
};

