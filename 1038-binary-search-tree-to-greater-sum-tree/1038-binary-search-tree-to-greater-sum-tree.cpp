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
    TreeNode* bstToGst(TreeNode* root) 
    {
        stack<TreeNode*> st;
        TreeNode *node = root;
        int sum = 0;
        
        while(true)
        {
            if(node!=NULL)
            {
                st.push(node);
                node = node->right;
            }
            else
            {
                if(st.empty())
                    break;
                node = st.top();
                st.pop();
                node->val += sum;
                sum = node->val;
                node = node->left;
            }
        }
        
        return root;
    }
};