class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string ans = "";
        int n = strs.size();
        
        for(int i=0; i<strs[0].size() ; i++)
        {
            bool check = true;
            for(int j=1 ; j<n ; j++)
            {
                if(i>=strs[j].size() || strs[j][i]!=strs[0][i])
                {
                    check = false;
                    break;
                }
            }
            
            if(check == false)
                break;
            else
                ans = ans+strs[0][i];
        }
        
        return ans;
    }
};