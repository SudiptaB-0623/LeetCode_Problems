class Solution 
{
public:
    int isPrefixOfWord(string sentence, string searchWord) 
    {
        int count = 0;
        
        vector<char> s;
        
        for(int i=0;i<=sentence.size();i++)
        {            
            int flag=-1;
            if(sentence[i]!=' ' && sentence[i]!='\0')
            {                
                s.push_back(sentence[i]);
            }
            else if(sentence[i]=' ' || sentence[i]=='\0')
            {
                count++;
                if(s.size()>=searchWord.size())
                {                    
                    flag=0;
                    for(int j=0;j<searchWord.size();j++)
                    {
                        if(s[j]!=searchWord[j])
                        {                            
                            flag++;
                            s={};
                            break;
                        }
                    }
                }
                s={};
            }
            if(flag==0)
                return count;
        }
        return -1;
    }
};