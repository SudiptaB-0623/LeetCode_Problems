class Solution 
{
public:
    int countPrefixes(vector<string>& words, string s) 
    {
        int count = 0;
        
        for(int i=0;i<words.size();i++)
        {
            int flag = 0;
            
            for(int j=0;j<(words[i]).size() && j<s.size();j++)
            {
                if((words[i])[j]!=s[j] || (words[i]).size()>s.size())
                {
                    flag++;
                    break;
                }
            }
            
            if(flag==0)
            {
                cout<<i<<(words[i])<<" ";
                count++;
            }
        }
        
        return count;
    }
};