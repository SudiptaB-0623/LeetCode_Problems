class Solution 
{
public:
    vector<string> fizzBuzz(int n) 
    {
        vector<string> s;
        string ch;
        for(int i=1;i<=n;i++)
        {
            if(i%3==0 && i%5==0)
            {
                s.push_back("FizzBuzz");
            }
            else if(i%3==0)
            {
                s.push_back("Fizz");
            }
            else if(i%5==0)
            {
                s.push_back("Buzz");
            }
            else
            {
                stringstream ss;
                ss<<i;
                ss>>ch;
                s.push_back(ch);
            }
        }
        return s;
    }
};
