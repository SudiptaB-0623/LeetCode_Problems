class Solution 
{
public:
    string stoneGameIII(vector<int>& stoneValue) 
    {
        int size = stoneValue.size();
        vector<int> vec(size + 1);
        
        for (int i = size - 1; i >= 0; i--) 
        {
            vec[i] = stoneValue[i] - vec[i + 1];
            if (i + 2 <= size) 
            {
                vec[i] = max(vec[i], stoneValue[i] + stoneValue[i + 1] - vec[i + 2]);
            }
            if (i + 3 <= size) 
            {
                vec[i] = max(vec[i], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - vec[i + 3]);
            }
        }
        
        if (vec[0] > 0) 
            return "Alice";
        if (vec[0] < 0) 
            return "Bob";
        
        return "Tie";
    }
};