class Solution 
{
public:
    void binary(int ind, vector<string> &ans, string temp, int num)
    {
        if(temp.size() == num)
        {
            ans.push_back(temp);
            return;
        }
        
        temp = temp + "1";
        binary(ind+1, ans, temp, num);
        temp.erase(temp.size()-1);
        if(temp.size()==0 || (temp.size()>0 && temp[temp.size()-1]!='0'))
        {
            temp = temp + '0';
            binary(ind+1, ans, temp, num);
        }
    }
    
    vector<string> validStrings(int n) 
    {
        vector<string> ans;
        string temp;
        
        binary(0, ans, temp, n);
        
        return ans;
    }
};