class Solution 
{
public:

    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) 
    {
        priority_queue<int,vector<int>,greater<int>> p(players.begin(),players.end());
        priority_queue<int,vector<int>,greater<int>> q(trainers.begin(),trainers.end());
        int ans=0;
        while(!p.empty() && !q.empty())
        {
            if(p.top()>q.top())q.pop();
            else if(p.top()<=q.top())
            {
                ans++;
                p.pop();
                q.pop();
            }
        }
        return ans;        
    }
};