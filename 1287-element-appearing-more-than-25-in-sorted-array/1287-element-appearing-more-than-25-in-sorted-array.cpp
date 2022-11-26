class Solution 
{
public:
    int findSpecialInteger(vector<int>& arr) 
    {
        int mark = arr.size() * 0.25;
        int flag = 1;
        
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]==arr[i-1])
            {
                flag++;
                if(flag>mark)
                    return arr[i];
            }
            else
            {
                flag=1;
            }
        }
        
        return arr[0];
    }
};