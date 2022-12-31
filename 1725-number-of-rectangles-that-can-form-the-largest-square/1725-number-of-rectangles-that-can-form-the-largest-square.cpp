class Solution 
{
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) 
    {
        map<int,int> mp;
        //cout<<rectangles.size()<<endl;
        
        for(int i=0;i<rectangles.size();i++)
        {
            int a = min(rectangles[i][0],rectangles[i][1]);
            //cout<<a<<endl;
            
            map<int,int> :: iterator it = mp.find(a);
            if(it!=mp.end())
                (it->second)++;
            else
                mp[a]=1;
        }
        map<int,int> :: iterator it = mp.begin();
        int max = it->second;
        int a = it->first;
        it++;
        
        for(;it!=mp.end();it++)
        {
            //cout<<it->first<<" "<<it->second<<" "<<max<<endl;
            if(it->first>a)
            {
                max=it->second;
                a=it->first;
            }
        }
        
        return max;
    }
};