class Solution 
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        vector<int> ans, temp = nums;
        sort(temp.begin(),temp.end());
        
        for(int i=0;i<temp.size();i++)
        {
            vector<int> :: iterator it;
            it = find(temp.begin(), temp.end(), nums[i]);            
            ans.push_back(it-temp.begin());
        }
        
        return ans;
    }
};