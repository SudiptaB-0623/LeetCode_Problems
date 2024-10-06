class Solution 
{
public:
    deque<string> toWords(string s, int n)
    {
        deque<string> q;
        
        string temp = "";
        for(int i=0; i<n; i++)
        {
            if(s[i] == ' ')
            {
                q.push_back(temp);
                temp = "";
            }
            else
                temp += s[i];
        }
        if(temp.size()>0)
            q.push_back(temp);
        
        return q;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) 
    {
        int n = sentence1.size();
        int m = sentence2.size();
        deque<string> q1 = toWords(sentence1, n);
        deque<string> q2 = toWords(sentence2, m);
        
        while(!q1.empty() && !q2.empty() && q1.front()==q2.front())
        {
            q1.pop_front();
            q2.pop_front();
        }
        
        while(!q1.empty() && !q2.empty() && q1.back()==q2.back())
        {
            q1.pop_back();
            q2.pop_back();
        }
        
        return q1.empty()||q2.empty();
    }
};