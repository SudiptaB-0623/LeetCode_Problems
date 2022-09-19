class Solution 
{
public:
    bool rotateString(string s, string goal) 
    {
        if(s.size()!=goal.size())
            return false;
        vector<char> v1,v2;
        int size=goal.size()-1;
        
        for(int i=0;i<s.size();i++)
        {
            v1.push_back(s[i]);
            v2.push_back(goal[i]);
        }
        if(v1==v2)
            return true;
        
        for(int i=0;i<s.size();i++)
        {
            v2.insert(v2.begin(),v2[size]);
            v2.pop_back();
            
            if(v1==v2)
                return true;
            
        }
        
        return false;
    }
};