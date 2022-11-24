class Solution 
{
public:
    double average(vector<int>& salary) 
    {
        double sum = accumulate(salary.begin(),salary.end(),0);
        sort(salary.begin(),salary.end());
        
        sum = sum - salary[0] - salary[salary.size()-1];
        
        return sum/(salary.size()-2);
    }
};