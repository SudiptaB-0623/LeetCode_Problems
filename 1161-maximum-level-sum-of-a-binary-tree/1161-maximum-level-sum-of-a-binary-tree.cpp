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
    int maxLevelSum(TreeNode* root) 
    {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        priority_queue<pair<long long int, int>> levelSums;
        levelSums.push({root->val, 1});
        int i=2;
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
                levelSums.push({sum, i});
                i = level;
                sum = node->val;
            }
        }
        levelSums.push({sum, i});
        
        int ans = INT_MAX;
        int maxSum = INT_MIN;
        while(!levelSums.empty())
        {
            pair<long long int, int> temp = levelSums.top();
            levelSums.pop();
            long long int sum = temp.first;
            int level = temp.second;
            
            if(sum > maxSum)
            {
                ans = level;
                maxSum = sum;
            }
            if(sum == maxSum)
                ans = min(ans, level);
        }
        return ans;
    }
};