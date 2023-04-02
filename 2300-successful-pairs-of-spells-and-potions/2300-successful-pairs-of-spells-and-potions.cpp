class Solution 
{
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        sort(potions.begin(),potions.end());
        vector<int> ans;                   
        
        for(int i=0;i<spells.size();i++)
        {
            int l = 0, h = potions.size()-1;
            int curr = potions.size();
            int spell = spells[i];
            
            while(l<=h)
            {
                int mid = l + (h-l)/2;                
                long long product = ((long long)spell)*potions[mid];
                
                if(product<success)
                    l = mid+1;
                else 
                {
                    curr = mid;
                    h = mid - 1;
                }
            }
            
            ans.push_back(potions.size()-curr);
        }
        
        return ans;
    }
};