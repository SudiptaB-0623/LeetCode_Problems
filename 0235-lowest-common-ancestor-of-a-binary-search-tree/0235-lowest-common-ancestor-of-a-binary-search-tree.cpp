/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        TreeNode *temp = root;
        
        while(temp!=NULL)
        {
            if(p->val<temp->val && q->val<temp->val)       //if both p & q are smaller than node, move left
            {
                temp = temp->left;
                continue;
            }
            if(p->val>temp->val && q->val>temp->val)       //if both p & q are greater than node, move right
            {
                temp = temp->right;
                continue;
            }
            return temp;                                   //if both p & q are not either small or larger than node, then the node is LCA
        }
        return NULL;
    }
};