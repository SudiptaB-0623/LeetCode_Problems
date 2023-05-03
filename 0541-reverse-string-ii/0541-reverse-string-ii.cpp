class Solution 
{
public:
    string reverseStr(string s, int k) 
    {
        int left = 0, right = 2*k, size = s.size();;
        while(left<s.size())
        {
            for(int i = left, j = min(left+k-1, size-1) ; i<j ; i++,j--)
            {
                swap(s[i],s[j]);
            }
            left = right;
            right += (2*k);
            //cout<<left<<" "<<right<<endl;
        }
        return s;
    }
};