class Solution 
{
public:
    int mostWordsFound(vector<string>& sentences) 
    {
        int count = 0;
        
        for(int i=0;i<sentences.size();i++)
        {
            int words = 1;
            
            for(int j=0;j<sentences[i].size();j++)
            {
                if((sentences[i][j]==' ')&&(j!=sentences[i].size()-1))
                {
                    if(sentences[i][j+1]!=' ')
                        words++;
                }
            }
            
            if((sentences[i].size()==1)&&(sentences[i][0]==' '))
                words = 0;
            
            if(words>count)
                count = words;
        }
        
        return count;
    }
};