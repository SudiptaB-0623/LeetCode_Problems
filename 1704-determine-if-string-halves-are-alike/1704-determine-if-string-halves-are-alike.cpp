class Solution 
{
public:
    
    bool isVowel(char ch)
    {
        switch (ch) 
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U': 
                return true;               
        }
        
        return false;
    }
    bool halvesAreAlike(string s) 
    {
        int a = 0, b = 0;
        
        for(int i=0, j=s.size()-1;i<s.size()/2;i++,j--)
        {
            if(isVowel(s[i]))
                a++;
            if(isVowel(s[j]))
                b++;
        }
        
        if(a==b)
            return true;
        else
            return false;
    }
};