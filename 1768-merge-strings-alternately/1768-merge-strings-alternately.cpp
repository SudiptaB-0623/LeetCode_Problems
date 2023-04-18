class Solution 
{
public:
    string mergeAlternately(string word1, string word2) 
    {
        string ans;
        for(int i=0, j=0, k=0;i<(word1.length()+word2.length());i++)
        {
            if(j<word1.length() && i%2==0)
            {
                ans.append(word1, j, 1);
                j++;
                if(j>=word1.length())
                {
                    ans.append(word2, k);
                    break;
                }
            }
            if(k<word1.length() && i%2!=0)
            {
                ans.append(word2, k, 1);
                k++;
                if(k>=word2.length())
                {
                    ans.append(word1, j);
                    break;
                }
            }
        }
        
        return ans;
    }
};