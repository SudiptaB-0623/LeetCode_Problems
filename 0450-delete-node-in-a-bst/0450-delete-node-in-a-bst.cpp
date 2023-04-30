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
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root==NULL)
            return NULL;
        
        if(root->val==key)
            return dnode(root);
        
        TreeNode *temp = root;
        while(temp!=NULL)
        {
            if(key<temp->val)
            {
                if(temp->left!=NULL && temp->left->val==key)
                {
                    temp->left = dnode(temp->left);
                    break;
                }
                else
                    temp = temp->left;
            }
            else
            {
                if(temp->right!=NULL && temp->right->val==key)
                {
                    temp->right = dnode(temp->right);
                    break;
                }
                else
                    temp = temp->right;
            }
        }
        return root;
    }
    TreeNode* dnode(TreeNode *todel)
    {
        if(todel->left==NULL)
            return todel->right;
        if(todel->right==NULL)
            return todel->left;
        
        TreeNode *rht = todel->right;
        TreeNode *last_right = lastright(todel->left); 
        last_right->right = rht;
        return todel->left;
    }
    TreeNode *lastright(TreeNode *root)
    {
        if(root->right==NULL)
            return root;
        
        return lastright(root->right);
    }
};