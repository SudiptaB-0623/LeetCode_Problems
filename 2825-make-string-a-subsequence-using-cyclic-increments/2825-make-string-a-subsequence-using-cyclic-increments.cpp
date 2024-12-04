class Solution 
{
public:
    bool canMakeSubsequence(string str1, string str2) 
    {
        int n = str1.size(), m = str2.size();
        
        int i=0, j = 0;
        for(; i<m ; i++)
        {
            bool status = false;
            for(; j<n ; j++)
            {                
                char temp = (str1[j] - 97 == 25) ? 'a' : str1[j]+1;
                if(str2[i]==str1[j] || str2[i]==temp)
                {
                    status = true;
                    j++;
                    break;
                } 
            }
            if(status == false)
                    return false;
        }
        
        return true;
    }
};