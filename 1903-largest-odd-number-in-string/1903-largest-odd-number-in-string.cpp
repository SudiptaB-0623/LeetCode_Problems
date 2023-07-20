class Solution 
{
public:
    // Note : Odd number means all that matters is the last digit.
    // So we check the last possible odd digit in the string, that would be the 
    // largest odd number
    
    string largestOddNumber(string num) 
    {
        for(int i=num.size()-1 ; i>=0 ; i--)
        {
            if(num[i]%2 != 0)               // Using num[i] directly because ASCII of odd numbers are also odd
                return num.substr(0, i+1);
        }
        return "";
    }
};