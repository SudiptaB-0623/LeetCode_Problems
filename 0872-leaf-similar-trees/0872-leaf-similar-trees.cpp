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
    void leaf(vector<int> &v, TreeNode *root)
    {
        stack<TreeNode*> st;
        st.push(root);
        
        while(st.empty()==false)
        {
            TreeNode *temp = st.top();
            st.pop();
            
            if((temp->left==NULL)&&(temp->right==NULL))
                v.push_back(temp->val);
            if(temp->right!=NULL)
                st.push(temp->right);
            if(temp->left!=NULL)
                st.push(temp->left);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> v1 = {}, v2 = {};
        leaf(v1, root1);
        leaf(v2, root2);
        
        if(v1==v2)
            return true;
        else
            return false;
    }
};