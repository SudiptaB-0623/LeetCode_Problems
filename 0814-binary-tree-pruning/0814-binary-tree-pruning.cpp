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
    void post(TreeNode *root, int target)
    {
        if(root == NULL)
            return;
        
        post(root->left, target);
        post(root->right, target);
        
        if(root->left!=NULL && root->left->val==-1)
        {
            TreeNode *temp = root->left;
            root->left = NULL;
            delete temp;
        }
        if(root->right!=NULL && root->right->val==-1)
        {
            TreeNode *temp = root->right;
            root->right = NULL;
            delete temp;
        }
        
        if((root->left==NULL && root->right==NULL) && root->val==target)
        {
            root->val = -1;
        }
    }
    TreeNode* pruneTree(TreeNode* root) 
    {
        post(root, 0);
        
        if((root->left==NULL && root->right==NULL) && (root->val==0 || root->val == -1))
            return NULL;
        
        return root;
    }
};