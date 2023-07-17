class Solution 
{
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack<int> st;
        for(int i = 0; i<asteroids.size() ; i++)
        {
            if(st.empty())
                st.push(asteroids[i]);
            else
            {
                if(st.top()<0)
                    st.push(asteroids[i]);
                else
                {
                    if(asteroids[i]<0)
                    {
                        bool to_push = true;
                        while(st.empty()!=true && st.top()>0)
                        {
                            if(abs(asteroids[i]) < st.top())
                            {
                                to_push = false;
                                break;
                            }
                            else if(abs(asteroids[i]) == st.top())
                            {
                                st.pop();
                                to_push = false;
                                break;
                            }
                            else
                                st.pop();
                        }
                        if(to_push == true)
                            st.push(asteroids[i]);
                    }
                    else
                        st.push(asteroids[i]);
                }
            }
        }
        
        vector<int> ans;
        
        while(st.empty()!=true)
        {
            int num = st.top();
            st.pop();
            ans.push_back(num);
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};