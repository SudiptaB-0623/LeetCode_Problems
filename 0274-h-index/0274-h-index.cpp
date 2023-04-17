class Solution 
{
public:
    int hIndex(vector<int>& citations) 
    {
            vector<int> v(1028, 0);
        
        for (int i : citations) 
            ++v[i];
        
        int total = size(citations), prev = 0;
        for (int i = 0; i != size(v); ++i)
        {
            int temp = v[i];
            total -= prev;
            v[i] = total;
            prev = temp;
        }
        
        int res = 0;
        for (int i = 0; v[i]; ++i) 
        {
            if (v[i] >= i && v[i + 1] <= i) 
            {
                res = i;
            }
        }
        
        return res;
    }
};