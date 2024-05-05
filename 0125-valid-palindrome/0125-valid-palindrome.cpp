class Solution 
{
public:
    bool isPalindrome(string s) 
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        bool ans = true;
        for(int i=0, j=s.size()-1 ; i<s.size();)
        {
            if(j<=i)
            {
                break;
            }
            else if(!iswalnum(s[i]))
            {
                i++;
                continue;
            }
            else if(!iswalnum(s[j]))
            {
                j--;
                continue;
            }
            else if(s[i] != s[j])
            {
                ans = false;
                break;
            }
            i++;
            j--;
        }
        
        return ans;
    }
};