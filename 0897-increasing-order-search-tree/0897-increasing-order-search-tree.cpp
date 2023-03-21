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
    TreeNode* increasingBST(TreeNode* root) 
    {
        stack<TreeNode*> st;
        TreeNode *node = root;
        TreeNode *new_root = new TreeNode();
        TreeNode *flag = new_root;
        
        int f = 0;
        
        while(true)
        {
            if(node!=NULL)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if(st.empty()==true)
                    break;
                node = st.top();
                st.pop();
                
                if(f==0)
                {
                    flag->val = node->val;
                    f++;
                }
                else
                {                    
                    TreeNode *temp = new TreeNode(node->val);
                    flag->right = temp;
                    flag = flag->right;
                }
                
                node = node->right;
            }
        }
        
        return new_root;
    }
};