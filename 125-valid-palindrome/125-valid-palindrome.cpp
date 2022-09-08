class Solution 
{
public:
    bool isPalindrome(string s) 
    {
        vector<char> str;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        
        for(int i=0;i<s.length();i++)
        {
            if(isalpha(s[i]) || isdigit(s[i])) 
            {
                
                str.insert(str.begin(),s[i]);
            }
                       
        }
        cout<<"size = "<<str.size();
        if(str.size()==0)
            return true;
        int size=str.size();
        
        for(int i=0,j=size-1;i<size/2;i++,j--)
        {
           
            if(str[i]!=str[j])
                return false;
        }
        return true;
    }
};