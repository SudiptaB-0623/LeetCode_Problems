class Solution 
{
public:
    string getPermutation(int n, int k) 
    {
        string ans = "";
        int temp = k-1;
        vector<int> numbers;
        int fact = 1;
        
        for(int i = 1; i<n ; i++)
        {
            fact = fact*i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        
        while(true)
        {
            if(numbers.size()==1)
                ans = ans + to_string(numbers[0]);
            else
                ans = ans + to_string(numbers[temp/fact]);
            numbers.erase(numbers.begin() + (temp/fact));
            
            if(numbers.size()==0)
                break;
            
            temp = temp%fact;
            fact = fact/(numbers.size());
        }
        
        return ans;
    }
};