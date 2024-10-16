class Solution 
{
public:
    string longestDiverseString(int a, int b, int c) 
    {
        priority_queue<pair<int, char>> pq;
        
        if(a>0)
            pq.push({a, 'a'});
        if(b>0)
            pq.push({b, 'b'});
        if(c>0)
            pq.push({c, 'c'});
        
        string ans = "";
        while(!pq.empty())
        {
            pair<int, char> curr = pq.top();
            pq.pop();
            
            int count = curr.first;
            char alpha = curr.second;
            
            int size = ans.size();
            if(size>=2 && ans[size-1]==alpha && ans[size-2]==alpha)
            {
                if(pq.empty())
                    break;
                
                pair<int, char> temp = pq.top();
                pq.pop();
                pq.push({count, alpha});
                count = temp.first;
                alpha = temp.second;
            }
                
            ans += alpha;
            count--;
            if(count>0)
                pq.push({count, alpha});
        }
        
        return ans;
    }
};