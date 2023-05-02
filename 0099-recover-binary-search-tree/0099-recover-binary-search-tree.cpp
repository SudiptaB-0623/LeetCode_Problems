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
    void in(TreeNode* root, TreeNode* &node1, TreeNode* &node2, TreeNode* &first)
    {
        if(root==NULL)
            return;
        in(root->left, node1, node2, first);
        if(first==NULL)
            first = root;
        else
        {
            if(root->val<first->val)
            {
                if(node1==NULL)
                    node1 = first;
                node2 = root;
                //cout<<node1->val<<" "<<node2->val;
            }
            first = root;
        }
        in(root->right, node1, node2, first);
    }
    void recoverTree(TreeNode* root) 
    {
        TreeNode *node1 = NULL;
        TreeNode *node2 = NULL;
        TreeNode* first = NULL;
        in(root, node1, node2, first);
        //cout<<node1->val<<" "<<node2->val;
        swap(node1->val,node2->val);
    }
};