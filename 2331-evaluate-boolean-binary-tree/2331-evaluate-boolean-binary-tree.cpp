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
    void post(TreeNode *root)
    {
        if(root==NULL)
            return;
        
        post(root->left);
        post(root->right);
        
        if(root->left!=NULL)
        {
            bool temp;
            if(root->val == 2)
            {
                temp = root->left->val || root->right->val;
            }
            else
            {
                temp = root->left->val && root->right->val;
            }
            if(temp==true)
                root->val = 1;
            else
                root->val = 0;
        }
    }
    bool evaluateTree(TreeNode* root) 
    {
        post(root);
        if(root->val == 1)
            return true;
        else
            return false;
    }
};