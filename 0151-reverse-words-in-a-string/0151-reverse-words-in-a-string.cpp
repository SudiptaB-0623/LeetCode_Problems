class Solution 
{
public:
    string reverseWords(string s) 
    {
        string ans = {};
                
        stringstream ss(s);
        istream_iterator<string> begin(ss);
        istream_iterator<string> end;
        vector<string> vstrings(begin, end);
              
        for(int i=vstrings.size()-1;i>=0;i--)
        {
            if(ans=="")
            {
                ans=vstrings[i];
            }
            else
            {
                ans=ans+" "+vstrings[i];
            }
        }
        
        return ans;
    }
};