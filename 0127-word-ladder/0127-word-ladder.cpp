class Solution 
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if(words.find(endWord) == words.end())
            return 0;
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        if(words.find(beginWord) != words.end())
            words.erase(beginWord);
        
        while(!q.empty())
        {
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(word == endWord)
                return level;
            
            for(int i=0; i<word.size(); i++)
            {
                string temp = word;
                for(char ch='a'; ch<='z'; ch++)
                {
                    temp[i] = ch;
                    if(words.find(temp) != words.end())
                    {
                        q.push({temp, level+1});
                        words.erase(temp);
                    }
                }
            }
        }
        
        return 0;
    }
};