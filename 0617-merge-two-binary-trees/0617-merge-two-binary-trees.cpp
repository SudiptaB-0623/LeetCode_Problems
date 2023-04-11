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
    void pre(TreeNode* r1, TreeNode* r2)
    {
        if(r1==NULL && r2==NULL)
            return;
        
        if(r1!=NULL && r2!=NULL)
            r1->val += r2->val;
        if(r1->left!=NULL && r2->left!=NULL)
            pre(r1->left, r2->left);
        else if(r1->left==NULL && r2->left!=NULL)
            r1->left = r2->left;
        
        if(r1->right!=NULL && r2->right!=NULL)
            pre(r1->right, r2->right);
        else if(r1->right==NULL && r2->right!=NULL)
            r1->right = r2->right;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        if(root1==NULL && root2==NULL)
            return NULL;
        else if(root1==NULL)
            return root2;
        else if(root2==NULL)
            return root1;
        
        pre(root1, root2);
        
        return root1;
    }
};