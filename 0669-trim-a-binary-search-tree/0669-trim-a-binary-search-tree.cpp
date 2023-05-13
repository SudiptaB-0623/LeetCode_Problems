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
    bool pre(TreeNode *&root, int l, int r)
    {
        if(root==NULL)
            return false;
        bool lt = pre(root->left, l, r);
        if(lt == true)
        {
            TreeNode *lchild = root->left->left;
            TreeNode *rchild = root->left->right;
            if(lchild!=NULL && rchild!=NULL)
            {
                root->left = lchild;
                root->left->right = rchild;
            }
            else if(lchild==NULL && rchild!=NULL)
            {
                root->left = rchild;
            }
            else if(lchild!=NULL && rchild==NULL)
            {
                root->left = lchild;
            }
            else if(lchild==NULL && rchild==NULL)
            {
                root->left = NULL;
            }
        }        
        
        bool rt = pre(root->right, l, r);
        if(rt == true)
        {
            TreeNode *lchild = root->right->left;
            TreeNode *rchild = root->right->right;
            if(lchild!=NULL && rchild!=NULL)
            {
                root->right = lchild;
                root->right->right = rchild;
            }
            else if(lchild==NULL && rchild!=NULL)
            {
                root->right = rchild;
            }
            else if(lchild!=NULL && rchild==NULL)
            {
                root->right = lchild;
            }
            else if(lchild==NULL && rchild==NULL)
            {
                root->right = NULL;
            }
        }
        
        if(root->val<l || root->val>r)
            return true;
        else
            return false;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) 
    {
        bool temp = pre(root, low, high);
        if(temp == true)
        {
            TreeNode *lchild = root->left;
            TreeNode *rchild = root->right;
            if(lchild!=NULL && rchild!=NULL)
            {
                root = lchild;
                root->right = rchild;
            }
            else if(lchild==NULL && rchild!=NULL)
            {
                root = rchild;
            }
            else if(lchild!=NULL && rchild==NULL)
            {
                root = lchild;
            }
            else if(lchild==NULL && rchild==NULL)
            {
                root = NULL;
            }
        }
        return root;
    }
};