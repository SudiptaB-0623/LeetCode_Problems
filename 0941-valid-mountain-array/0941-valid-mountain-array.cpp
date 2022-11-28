class Solution 
{
public:
    bool validMountainArray(vector<int>& arr) 
    {
        if(arr.size()<3)
            return false;
        
        int flag = 0;
        
        for(int i=1;i<arr.size();i++)
        {            
            if(arr[i]==arr[i-1])
                return false;
            
            if(flag==0)
            {
                if(arr[i]>arr[i-1])
                    continue;
                else
                {
                    if(i==1)
                        return false;
                    flag=1;
                }
            }
            else
            {
                if(arr[i]<arr[i-1])
                    continue;
                else
                    return false;
            }
        }
        
        if(flag==0)
            return false;
        else        
            return true;
    }
};