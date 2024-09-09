class Solution 
{
public:
    void parenthesis(int ind, vector<string> &ans, string temp, int left, int right)
    {
        if(left == 0 && right == 0)
        {
            ans.push_back(temp);
            return;
        }
        
        if(left>0)
        {
            temp = temp + "(";
            parenthesis(ind+1, ans, temp, left-1, right);
            temp.erase(temp.size()-1);
        }
        if(ind!=0 && left<right)
        {
            temp = temp + ")";
            parenthesis(ind+1, ans, temp, left, right-1);
        }
    }
    
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        string temp;
        
        parenthesis(0, ans, temp, n, n);
        
        return ans;
    }
};