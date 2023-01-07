class Solution 
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int gsum = accumulate(gas.begin(),gas.end(),0);
        int csum = accumulate(cost.begin(),cost.end(),0);
        
        if(gsum<csum)
            return -1;
        
        int curr_gas = 0, start = 0;
        
        for(int i=0;i<gas.size();i++)
        {
            curr_gas += gas[i]-cost[i];
            if(curr_gas<0)
            {
                curr_gas = 0;
                start = i+1;
            }
        }
        if(start<gas.size())
            return start;
        else
            return -1;
    }
};