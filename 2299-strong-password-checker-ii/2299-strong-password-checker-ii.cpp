class Solution 
{
public:
    bool strongPasswordCheckerII(string password) 
    {
        if(password.length()<8)
            return false;
        int lc=0,uc=0,dig=0,sc=0;
        for(int i=0;i<password.length();i++)
        {
            
            if(int(password[i])>=48 && int(password[i])<=57)
                dig++;
            if(int(password[i])>=65 && int(password[i])<=90)
                lc++;
            if(int(password[i])>=97 && int(password[i])<=122)
                uc++;
            if(password[i]=='!' || password[i]=='@' || password[i]=='#' || password[i]=='$' || password[i]=='%' || password[i]=='^' || password[i]=='&' || password[i]=='*' || password[i]=='(' || password[i]==')' || password[i]=='-' || password[i]=='+')
                sc++;
            if(i!=password.length()-1 )
                 if(password[i]==password[i+1])
                     return false;
        }
        if(lc>0 && uc>0 && dig>0 && sc>0)
            return true;
        else
            return false;
    }
};