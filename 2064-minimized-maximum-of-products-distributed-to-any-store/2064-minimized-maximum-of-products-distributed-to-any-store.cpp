class Solution 
{
public:
    bool canDistribute(int x, vector<int>& quantities, int n) 
    {
        int temp = 0;
        int remaining = quantities[temp];

        for(int i = 0; i < n; i++) 
        {
            if(remaining <= x) 
            {
                temp++;
                if(temp == quantities.size())
                    return true;
                else 
                    remaining = quantities[temp];
            } 
            else 
                remaining -= x;
        }
        return false;
    }
    
    int minimizedMaximum(int n, vector<int>& quantities) 
    {
        int left = 0;
        int right = *max_element(quantities.begin(), quantities.end());

        while(left < right) 
        {
            int middle = (left + right) / 2;
            if(canDistribute(middle, quantities, n)) 
                right = middle;
            else 
                left = middle + 1;
        }
        return left;
    }
};