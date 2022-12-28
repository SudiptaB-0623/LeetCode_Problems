class Solution 
{
public:
    int minStoneSum(vector<int>& piles, int k) 
    {
        priority_queue<int> pq;
        int ans = 0;
        
        for(int i=0;i<piles.size();i++)
        {
            pq.push(piles[i]);
        }
        for(int i=0;i<k;i++)
        {
            float a = pq.top();            
            a=ceil(a/2.0);
            pq.pop();
            pq.push(a);
        }
                
        for(int i=0;i<piles.size();i++)
        {
            ans += pq.top();            
            pq.pop();
        }
        
        return ans;
    }
};