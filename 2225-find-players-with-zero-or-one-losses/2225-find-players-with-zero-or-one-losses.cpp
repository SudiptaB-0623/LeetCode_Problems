class Solution 
{
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
        map<int,pair<int,int>> mpp;
        vector<int> win,lose;
        vector<vector<int>> ans;
        //map<int, pair<int,int>>::iterator itx;
        
        for(int i=0;i<matches.size();i++)
        {
            auto it = mpp.find(matches[i][0]);
            if(it!=mpp.end())
            {
                ((it->second).first)++;
            }
            else
            {
                mpp.insert({matches[i][0],{1,0}});
            }
            auto itr = mpp.find(matches[i][1]);
            if(itr!=mpp.end())
            {
                ((itr->second).second)++;
            }
            else
            {
                mpp.insert({matches[i][1],{0,1}});
            }
            /*cout<<i<<endl;
            for (auto itx=mpp.begin(); itx != mpp.end(); ++itx)
            {
                cout<<itx->first<<" "<<(itx->second).first<<" "<<(itx->second).second<<endl;
            }*/
        }
        
        for (auto itx=mpp.begin(); itx != mpp.end(); ++itx)
        {
            //cout<<itx->first<<" "<<(itx->second).first<<" "<<(itx->second).second<<endl;
            if((itx->second).second==0)
                win.push_back(itx->first);
            if((itx->second).second==1)
                lose.push_back(itx->first);
        }
                
        ans.push_back(win);
        ans.push_back(lose);
        
        return ans;
    }
};