class Solution 
{
public:
    int beautySum(string s) 
    {        
        int totBeauty = 0;
        int n = s.size();
                
        for(int i=0 ; i<n ; i++)
        {
            vector<int> alpha(26, 0);            
            for(int j=i ; j<n ; j++)
            {
                alpha[s[j] - 'a']++;
                int maxi = alpha[s[j] - 'a'];
                int mini = alpha[s[j] - 'a'];
                for(int k=0 ; k<26 ; k++)
                {
                    if(alpha[k] > maxi)
                        maxi = alpha[k];
                    if(alpha[k] < mini && alpha[k]!=0)
                        mini = alpha[k];
                }
                
                totBeauty += maxi-mini;
            }
        }
        
        return totBeauty;
    }
};