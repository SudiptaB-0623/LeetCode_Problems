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
    bool pre(TreeNode *root, int num)
    {
        if(root==NULL)
            return true;
        
        bool lh = pre(root->left, num);
        if(lh == false)
            return false;
        bool rh = pre(root->right, num);
        if(rh == false)
            return false;
        
        return (lh && rh && (root->val==num));
    }
    bool isUnivalTree(TreeNode* root) 
    {
        int num = root->val;
        
        return pre(root, num);
    }
};