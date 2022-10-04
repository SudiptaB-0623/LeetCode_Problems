class Solution 
{
public:
    int prefixCount(vector<string>& words, string pref) 
    {
        if(words.size() == 0)
            return 0;
        int count=0;
        
        for(int i=0;i<words.size();i++)
        {
            int flag=0;
            for(int j=0;j<pref.size();j++)
            {
                if((words[i])[j] != pref[j])
                {
                    flag++;
                    break;
                }
            }
            if(flag==0)
                count++;
        }
        
        return count;
    }
};