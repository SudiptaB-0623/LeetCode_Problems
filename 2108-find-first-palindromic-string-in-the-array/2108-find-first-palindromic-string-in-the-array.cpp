class Solution 
{
public:
    string firstPalindrome(vector<string>& words) 
    {
        if(words.size() == 0)
            return NULL;
        string s={};
        
        for(int i=0;i<words.size();i++)
        {
            int flag=0;
            for(int j=0,k=((words[i]).size())-1;j<k;j++,k--)
            {
                if((words[i])[j]!=(words[i])[k])
                {
                    flag++;
                    break;
                }
            }
            if(flag==0)
                return words[i];
        }
        
        return s;
    }
};