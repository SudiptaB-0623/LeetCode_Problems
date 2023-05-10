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
    void rev_in(TreeNode *root, int &sum)
    {
        if(root==NULL)
            return;
        
        rev_in(root->right, sum);
        root->val += sum;
        sum = root->val;
        rev_in(root->left, sum);
    }
    TreeNode* convertBST(TreeNode* root) 
    {
        if(root==NULL)
            return NULL;
        int sum = 0;
        rev_in(root, sum);
        return root;
    }
};