class Solution 
{
public:
    int totalFruit(vector<int>& fruits) 
    {
        int n = fruits.size();
        int ans = 0;
        int left = 0, right = 0;
        vector<int> fruit(2, -1);
        vector<int> freq(2, 0);
        
        while(right<n)
        {
            if(freq[0] == 0 || fruits[right]==fruit[0])
            {
                freq[0]++;
                fruit[0] = fruits[right];
            }
            else if(freq[1] == 0 || fruits[right]==fruit[1])
            {
                freq[1]++;
                fruit[1] = fruits[right];
            }
            else if(fruits[right]!=fruit[0] && fruits[right]!=fruit[1])
            {
                while(freq[0]!=0 && freq[1]!=0)
                {
                    if(fruits[left]==fruit[0])
                        freq[0]--;
                    else
                        freq[1]--;
                    
                    left++;
                }
                
                if(freq[0]==0)
                {
                    freq[0]=1;
                    fruit[0]=fruits[right];
                }
                else
                {
                    freq[1] = 1;
                    fruit[1]=fruits[right];
                }
            }
            
            ans = max(ans, right-left+1);
            right++;
        }
        
        return ans;
    }
};