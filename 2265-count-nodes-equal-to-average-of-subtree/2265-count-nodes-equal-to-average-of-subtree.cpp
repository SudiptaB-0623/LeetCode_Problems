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
    int avrg(TreeNode *root, int &ans)
    {
        if(root==NULL)
            return 0;
        
        int lh = avrg(root->left, ans);
        int rh = avrg(root->right, ans);
        
        if(root->left==NULL && root->right==NULL) 
        {
            ans++;
            return 1;
        }
        //cout<<root->val<<endl;
        int l , r;
        if(root->left==NULL)
            l = 0;
        else
            l = root->left->val;
        if(root->right==NULL)
            r = 0;
        else
            r = root->right->val;
        if(root->val == (root->val + l + r)/(lh + rh + 1))
            ans++;
        root->val += (l + r);
        return lh+rh+1;
        
    }
    int averageOfSubtree(TreeNode* root) 
    {
        int ans = 0;
        int t_nodes = avrg(root, ans);
        return ans;
    }
};