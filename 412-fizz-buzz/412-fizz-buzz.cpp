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
                /*int newi=0;
                if(n/10!=0)
                {
                    while(n!=0)
                    {
                        newi=newi+(n%10);
                        n=n/10;
                    }
                    while(newi!=0)
                    {
                        n=newi%10;
                        c=48+n;
                        ch.push_back(c);
                    }
                }
                ch=48+i;
                //cout<<c;*/
                stringstream ss;
                ss<<i;
                ss>>ch;
                s.push_back(ch);
            }
        }
        return s;
    }
};