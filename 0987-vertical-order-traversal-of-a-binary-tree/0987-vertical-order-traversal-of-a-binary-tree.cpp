/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int,int>>> nodes;
        nodes.push({root, {0,0}});
        
        map<int, map<int, multiset<int>>> mpp;
        
        while(!nodes.empty())
        {
            auto temp = nodes.front();
            nodes.pop();
            int x = temp.second.first;
            int y = temp.second.second;
            TreeNode *curr = temp.first;
            
            mpp[y][x].insert(curr->val);
            
            if(curr->left)
            {
                nodes.push({curr->left, {x+1,y-1}});
            }
            if(curr->right)
            {
                nodes.push({curr->right, {x+1,y+1}});
            }
        }
        
        for(auto p : mpp)
        {
            vector<int> ver;
            for(auto q : p.second)
            {
                ver.insert(ver.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(ver);
        }
        return ans;
    }
};