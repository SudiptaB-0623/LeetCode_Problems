class Solution 
{
public:
    double calculateTax(vector<vector<int>>& brackets, int income) 
    {
        double tax=0;
        
        if(income==0)
            return tax;
        double cmp=brackets[0][0];
        int i=0;
        
        for(;income>cmp;i++)
        {
            tax=tax+((cmp*brackets[i][1])/100.0);
            cout<<"   "<<tax;
            income=income-cmp;
            
                      
            if(i<brackets.size())
            {
                cmp=brackets[i+1][0]-brackets[i][0];
            }
        }
        
        tax=tax+(income*brackets[i][1])/100.0;
        return tax;
        
        return 0;
    }
};