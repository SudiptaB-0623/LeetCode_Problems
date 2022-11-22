class Solution 
{
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        vector<bool> ans;
        
        for(int i=0;i<candies.size();i++)
        {
            int temp = candies[i];
            candies[i]+=extraCandies;
            
            int max_ele = *max_element(candies.begin(),candies.end());
            if(max_ele == candies[i])
                ans.push_back(true);
            else
                ans.push_back(false);
            
            candies[i] = temp;
        }
        
        return ans;
    }
};