class Solution 
{
public:
    string compressedString(string word) 
    {
        int n = word.size();        
        string comp = "";
        int pos = 0;
        
        while(pos < n) 
        {
            int count = 0;
            char ch = word[pos];
            
            while(pos < n && count < 9 && word[pos] == ch) 
            {
                count++;
                pos++;
            }

            comp += to_string(count) + ch;
        }

        return comp;
    }
};