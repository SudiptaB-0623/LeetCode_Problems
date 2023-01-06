class Solution 
{
public:
    int maxIceCream(vector<int>& costs, int coins) 
    {
        sort(costs.begin(),costs.end());
        int ans = 0;
        
        for(int i=0,j=coins;i<costs.size();i++)
        {
            if(j>=costs[i])
            {
                j-=costs[i];
                ans++;
            }
            else
                break;
        }
        return ans;
    }
};