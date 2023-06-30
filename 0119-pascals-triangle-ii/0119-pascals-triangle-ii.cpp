class Solution 
{
public:
    vector<int> getRow(int rowIndex) 
    {
        long long curr = 1;
        vector<int> ans;
        
        for(int i=0; i<rowIndex+1 ; i++)
        {
            if(i>0)
            {
                curr = (curr * (rowIndex+1-i));
                curr = (curr/i);
                //curr = curr%(1e9+7);
            }
            ans.push_back(curr);
        }
        
        return ans;
    }
};