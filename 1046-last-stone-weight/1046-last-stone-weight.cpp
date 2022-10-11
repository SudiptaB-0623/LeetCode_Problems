class Solution 
{
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        if(stones.size()==1)
            return stones[0];
        
        vector<int>::iterator it;
        sort(stones.begin(),stones.end());                    
        
        while(stones.size()>1)
        { 
            if(stones[stones.size()-1] == stones[stones.size()-2])
            {
                it = stones.end()-1;
                stones.erase(it);
                it = stones.end()-1;
                stones.erase(it);
            }
            else
            {
                stones[stones.size()-2]=stones[stones.size()-1]-stones[stones.size()-2];
                it = stones.end()-1;
                stones.erase(it);
            }
            sort(stones.begin(),stones.end());
        }
        
        if(stones.size()==1)
            return stones[0];
        else
            return 0;
    }
};