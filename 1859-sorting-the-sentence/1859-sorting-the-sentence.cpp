class Solution 
{
public:
    string sortSentence(string s) 
    {
        string ans = "";
        map<char, string> mpp;
        string temp;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] != ' ')
            {
                temp += s[i];
            }
            else
            {
                temp.pop_back();
                mpp.insert({s[i-1], temp});
                temp.clear();
            }
        }
        temp.pop_back();
        mpp.insert({s[s.size()-1], temp});
        
        for(auto it : mpp)
        {
            if(ans!="")
                ans = ans + " " + it.second;
            else
                ans = it.second;
        }
        return ans;
    }
};