class Solution 
{
public:
    vector<int> pathInZigZagTree(int label) 
    {
        vector<int> ans = {label};
        int h = 0;
        
        for(int i = 0; i< label;)
        {
            i += pow(2,h);
            h++;
        }
        
        while(label>1)
        {
            h--;
            int min = pow(2,h-1);
            int max = pow(2,h)-1;
            
            label = min + max - (label/2);
            //cout<<min<<" "<<min<<" "<<label<<endl;
            ans.insert(ans.begin(),label);
        }
        
        return ans;
    }
};