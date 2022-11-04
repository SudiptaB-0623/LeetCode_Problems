class Solution 
{
public:
    string reverseVowels(string s) 
    {
        vector<char> vec;
        
        for(int i=0;i<s.size();i++)
        {
            cout<<s[i]<<" ";
            if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='i' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' )
            {
                vec.push_back(s[i]);
            }
        }
        
        int j = vec.size()-1;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='i' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' )
            {
                s[i] = vec[j];
                j--;
            }
        }
        
        return s;
    }
};