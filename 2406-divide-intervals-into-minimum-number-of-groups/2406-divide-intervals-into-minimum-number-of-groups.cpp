class Solution 
{
public:
    int minGroups(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pqueue;
        int ans = 0;
        
        for(int i=0;i<intervals.size();i++)
        {
            if(pqueue.size() == 0)
            {
                pqueue.push(intervals[i][1]);
                ans++;
            }
            else
            {
                if(pqueue.top() >= intervals[i][0])
                {
                    pqueue.push(intervals[i][1]);
                    ans++;
                }
                else
                {
                    pqueue.pop();
                    pqueue.push(intervals[i][1]);
                }
            }
        }        
        return ans;
    }
};