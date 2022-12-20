class Solution 
{
public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
        vector<string> ans;
        
        for(int i=0,j=1;i<target.size();j++)
        {
            
            if(target[i]==j)
            {
                ans.push_back("Push");
                i++;
            }             
            
            else
            {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};