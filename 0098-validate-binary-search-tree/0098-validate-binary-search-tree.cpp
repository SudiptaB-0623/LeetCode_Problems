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
    void pre(TreeNode *root, vector<int> &vals)
    {
        if(root==NULL)
            return;
        
        pre(root->left, vals);
        vals.push_back(root->val);
        pre(root->right, vals);
        
        return;
    }
    
    bool isValidBST(TreeNode* root) 
    {
        vector<int> vals;
        pre(root, vals);
        
        int size = vals.size();
        ;
        for(int i=0;i<size-1;i++)
        {
            cout<<vals[i]<<" ";
            if(vals[i]>=vals[i+1])
                return false;
        }
        return true;
    }
};