class Solution 
{
public:

    #define ll long long
    void dfs(int source,vector<int>& vec,vector<int> adj[])
    {
        vec[source]=1;
        for(int x:adj[source])
        {
            if(vec[x]==0)
            {
                dfs(x,vec,adj);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) 
    {
        
          int n = bombs.size();
          vector<int> adj[n];

        for(int i=0;i<n;i++)
        {

            ll r1=bombs[i][2];
            ll x1=bombs[i][0];
            ll y1=bombs[i][1];

            for(int j=0;j<n;j++)
            {

                if(i!=j)
                {

                    ll x2=bombs[j][0];
                    ll y2=bombs[j][1];
                    ll r2=bombs[j][2];
                    ll dsq=(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);;
                    if(dsq<=r1*r1)
                    {
                        adj[i].push_back(j); 
                    }
                }
            }
        }

        vector<int> vctr(n);
        int res=0;

        for(int i=0;i<n;i++)
        {

            dfs(i,vctr,adj); 
            int count=0;

            for(int j=0;j<n;j++) 
              if(vctr[j]==1) count++;

            res=max(res,count);
            fill(vctr.begin(),vctr.end(),0);
        }

        return res;
    }
};