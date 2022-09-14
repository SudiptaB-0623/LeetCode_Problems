class Solution 
{
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) 
    {
        int count=0;
        for(int i=0;tickets[k]!=0;i++)
        {
            
            if(tickets[i]!=0)
            {
                tickets[i]=tickets[i]-1; 
                count++;
            }
            //cout<<i<<endl;
            if(i==tickets.size()-1)
                i=-1;
        }
        return count;
    }
};