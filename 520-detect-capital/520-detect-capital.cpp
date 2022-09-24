class Solution 
{
public:
    bool detectCapitalUse(string word) 
    {
        int size=word.length();
        
        if(size==1)
        {
           return true;
        }
                    
        int test1=0, test2=0;
        
        if(isupper(word[0]))
        {
            test1=1;
            if(isupper(word[1]))
               test2=1;
        }
        
        if(test1==1 && test2==1)
        {
            for(int i=2;i<size;i++)
            {
                if(isupper(word[i]))
                    continue;
                else
                    return false;
            }
            return true;
        }
        else if(test1==1 && test2==0)
        {
            for(int i=2;i<size;i++)
            {
                if(islower(word[i]))
                    continue;
                else
                    return false;
            }
            return true;
        }
        else if(test1==0)
        {
            for(int i=1;i<size;i++)
            {
                if(islower(word[i]))
                    continue;
                else
                    return false;
            }
            return true;
        }
        
        return true;
        
    }
};