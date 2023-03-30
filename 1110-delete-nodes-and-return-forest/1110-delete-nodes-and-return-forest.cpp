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
    void post(TreeNode *root, vector<int> del, vector<TreeNode*> &ans)
    {
        if(root==NULL)
            return;
        
        post(root->left, del, ans);
        post(root->right, del, ans);
        
        vector<int> :: iterator it;
        it = find(del.begin(),del.end(),root->val);
        if(it!=del.end())
        {
            root->val = -1;
        }
        
        if((root->left!=NULL) && (root->left->val == -1))
        {
            if(root->left->left!=NULL)
                ans.push_back(root->left->left);
            if(root->left->right!=NULL)
                ans.push_back(root->left->right);
            root->left = NULL;
        }
        if((root->right!=NULL) && (root->right->val == -1))
        {
            if(root->right->left!=NULL)
                ans.push_back(root->right->left);
            if(root->right->right!=NULL)
                ans.push_back(root->right->right);
            root->right = NULL;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
        vector<TreeNode*> ans;
        
        if(root==NULL)
            return ans;
        
        post(root, to_delete, ans);
        
        if((root!=NULL) && (root->val == -1))
        {
            if(root->left!=NULL)
                ans.push_back(root->left);
            if(root->right!=NULL)
                ans.push_back(root->right);
            root = NULL;
        }
        else
            ans.push_back(root);
        
        return ans;
    }
};