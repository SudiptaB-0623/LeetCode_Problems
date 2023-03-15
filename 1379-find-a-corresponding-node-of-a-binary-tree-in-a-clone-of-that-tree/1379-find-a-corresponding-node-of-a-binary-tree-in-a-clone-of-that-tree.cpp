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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
        
        TreeNode *temp=original, *flag=cloned, *ans=original;
        
        inorder(temp, flag, target, ans);
        
        return ans;
    }
    
    void inorder(TreeNode* temp, TreeNode* flag, TreeNode* target, TreeNode* &ans)
    {
        
        if(temp==NULL)
            return;
        
        inorder(temp->left, flag->left, target, ans);
        
        if(temp==target) 
            ans = flag;
    
        inorder(temp->right, flag->right, target, ans);            
    }
};