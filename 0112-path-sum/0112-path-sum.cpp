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
    void pre(TreeNode *root, int target, bool &ans, int &sum)
    {
        if(root==NULL)
            return;
        
        sum += root->val;
        if(root->left==NULL && root->right==NULL)
        {
            if(sum==target)
                ans = true;
        }
        pre(root->left, target, ans, sum);
        pre(root->right, target, ans, sum);
        sum -= root->val;
        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        bool ans = false;
        int sum = 0; 
        pre(root, targetSum, ans, sum);
        
        return ans;
    }
};