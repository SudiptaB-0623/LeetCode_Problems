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
    TreeNode* bst(vector<int> &pre, int &i, int max)
    {
        if(i>=pre.size() || pre[i]>=max)
            return NULL;
        
        TreeNode *root = new TreeNode(pre[i]);
        i++;
        root->left = bst(pre, i, root->val);
        root->right = bst(pre, i, max);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        int count = 0;        
        TreeNode *root = bst(preorder, count, INT_MAX);
        
        return root;
    }
};