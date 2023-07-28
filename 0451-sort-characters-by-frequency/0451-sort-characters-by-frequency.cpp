bool comp(pair<char, int> &a, pair<char, int> &b)
{
    return a.second > b.second;
}
class Solution 
{
public:    
    vector<pair<char, int>> mapsort(map<char, int> &mp)
    {
        vector<pair<char, int>> pr;
        
        for(auto it : mp)
            pr.push_back(it);
        
        sort(pr.begin(), pr.end(), comp);
        
        return pr;
    }
    
    string frequencySort(string s) 
    {
        map<char, int> mpp;
        string ans = "";
        
        for(int i=0; i<s.size(); i++)
        {
            mpp[s[i]]++;
        }
        vector<pair<char, int>> vec = mapsort(mpp);
        for(int i=0; i<vec.size(); i++)
        {
            int freq = vec[i].second;
            while(freq>0)
            {
                ans+=vec[i].first;
                freq--;
            }
        }
        
        return ans;
    }
};