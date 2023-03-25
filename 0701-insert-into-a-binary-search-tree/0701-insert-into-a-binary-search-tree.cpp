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
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        TreeNode *target = new TreeNode(val);
        TreeNode *temp = root;
        
        if(root==NULL)
            return target;
        
        while(true)
        {
            if(val>temp->val)
            {
                if(temp->right!=NULL)
                {
                    temp=temp->right;
                    continue;
                }
                else
                {
                    temp->right = target;
                    break;
                }
            }
            else
            {
                if(temp->left!=NULL)
                {
                    temp=temp->left;
                    continue;
                }
                else
                {
                    temp->left = target;
                    break;
                }
            }
        }
        
        return root;
    }
};