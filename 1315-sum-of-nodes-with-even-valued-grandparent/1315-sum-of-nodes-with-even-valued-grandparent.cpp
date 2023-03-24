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
    int sumEvenGrandparent(TreeNode* root) 
    {
        stack<TreeNode*> st;
        st.push(root);
        int sum = 0;
        
        while(st.empty()==false)
        {
            root = st.top();
            st.pop();
            
            if(root->val%2 == 0)
            {
                if(root->right!=NULL)
                {
                    if(root->right->right!=NULL)
                        sum += root->right->right->val;
                    if(root->right->left!=NULL)
                        sum += root->right->left->val;
                }
                if(root->left!=NULL)
                {
                    if(root->left->right!=NULL)
                        sum += root->left->right->val;
                    if(root->left->left!=NULL)
                        sum += root->left->left->val;
                }
            }
            if(root->right!=NULL)
                st.push(root->right);
            if(root->left!=NULL)
                st.push(root->left);   
        }
        
        return sum;
    }
};