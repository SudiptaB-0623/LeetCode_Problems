class Solution {
public:
    vector<vector<int>> adjList;
    int dfs(vector<bool>& hasApple, int node, int d, int prev)
    {
        int ans=0,flag;
        for(int &i:adjList[node])
        {
            if(i!=prev)
            {
                flag=dfs(hasApple,i,d+1,node);
                if(flag) ans+=flag-d;
            }
        }
        return (ans||hasApple[node]?ans+d:0); 
        
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        adjList.resize(n);
        for(vector<int> &e:edges)
        {
            adjList[e[0]].push_back(e[1]),adjList[e[1]].push_back(e[0]);
        }
        return dfs(hasApple,0,0,-1)*2;
    }
};