class Solution 
{
public:
    int wateringPlants(vector<int>& plants, int capacity) 
    {
        int steps = 0;
        int cpy = capacity;
        
        for(int i =0;i<plants.size();i++)
        {
            if(capacity>=plants[i])
            {
                steps++;
                capacity = capacity - plants[i];
            }
            else
            {
                capacity = cpy;
                steps = steps + (i*2);
                steps++;
                capacity = capacity - plants[i];
            }
        }
        
        return steps;
    }
};