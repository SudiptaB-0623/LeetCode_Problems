class Solution 
{
public:
    vector<int> diffWaysToCompute(string expression) 
    {
        vector<int> ans;
        
        if(expression.size()==1)
        {
            ans.push_back(stoi(expression));
            return ans;
        }
        if(expression.size()==2 && isdigit(expression[0])==true)
        {
            ans.push_back(stoi(expression));
        }
        
        for(int i=0; i<expression.size(); i++)
        {
            if(isdigit(expression[i]))
                continue;
            
            vector<int> left = diffWaysToCompute(expression.substr(0, i));
            vector<int> right = diffWaysToCompute(expression.substr(i+1));
            
            char currChar = expression[i];            
            for(int m=0; m<left.size(); m++)
            {
                for(int n=0; n<right.size(); n++)
                {
                    int res = 0;
                    if(currChar == '+')
                        res = left[m]+right[n];
                    else if(currChar == '-')
                        res = left[m]-right[n];
                    else if(currChar == '*')
                        res = left[m]*right[n];
                    
                    ans.push_back(res);
                }
            }
        }
        
        return ans;
    }
};