class Solution 
{
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) 
    {
        vector<int> r;
        
        for(int i=0;i<capacity.size();i++)
        {
            r.push_back(capacity[i]-rocks[i]);
        }
        
        sort(r.begin(),r.end());
        
        int ans=0, sum=0;
        
        for(int i=0;i<r.size();i++)
        {
            sum += r[i];
            
            if(sum>additionalRocks)
                break;
            else
                ans++;
        }
        
        return ans;
    }
};