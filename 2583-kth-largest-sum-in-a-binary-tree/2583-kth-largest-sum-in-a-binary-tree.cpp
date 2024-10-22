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
    long long kthLargestLevelSum(TreeNode* root, int k) 
    {        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        priority_queue<long long int> levelSums;
        levelSums.push(root->val);
        int i=1;
        long long int sum = 0;
        
        while(!q.empty())
        {
            pair<TreeNode*, int> temp = q.front();
            q.pop();
            TreeNode *node = temp.first;
            int level = temp.second;
            
            if(node->left!=NULL)
                q.push({node->left, level+1});
            if(node->right!=NULL)
                q.push({node->right, level+1});
            
            
            if(level == i)
                sum += node->val;
            if(level>i)
            {
                levelSums.push(sum);
                i = level;
                sum = node->val;
            }
        }
        levelSums.push(sum);
        
        for(int i=1; i<k && !levelSums.empty(); i++)
            levelSums.pop();
        
        if(!levelSums.empty())
            return levelSums.top();
        
        return -1;
    }
};