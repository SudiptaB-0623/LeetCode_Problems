class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        if(x<0 && (x/10 == 0))
            return false;
        if(x==0)
            return true;
        vector<int> vec;
        
        int y = x;
        
        while(y!=0)
        {
            if(y/10 == 0)
                vec.push_back(y%10);
            else                  
                vec.push_back(abs(y%10));            
            y = y/10;
        }
        
        for(int i=0,j=vec.size()-1;i<=vec.size()/2;i++,j--)
        {
            if(vec[i]==vec[j])
                continue;
            else
                return false;
        }
        return true;
    }
};