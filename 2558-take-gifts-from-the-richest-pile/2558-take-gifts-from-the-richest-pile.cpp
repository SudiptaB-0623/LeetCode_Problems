class Solution
{
public:
    long long pickGifts(vector<int>& gifts, int k) 
    {
        int n = gifts.size();
        for(int i = 0; i < k; i++) 
        {
            int richInd = 0;

            for(int i = 0; i < n; i++)
            {
                if(gifts[richInd] < gifts[i]) 
                    richInd = i;
            }
            gifts[richInd] = sqrt(gifts[richInd]);
        }

        long long int ans = accumulate(gifts.begin(), gifts.end(), 0LL);

        return ans;
    }
};