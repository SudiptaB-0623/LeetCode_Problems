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
    void post_trav(TreeNode *root, int &num, int &ans)
    {
        if(root==NULL)
            return;
        
        num = (num*10)+root->val;
        post_trav(root->left, num, ans);
        post_trav(root->right, num, ans);
        //num = (num*10)+root->val;
        if(root->left==NULL && root->right==NULL)
        {
            ans += num;
            //cout<<num<<endl;
        }
        num = num/10;
    }
    
    int sumNumbers(TreeNode* root) 
    {
        int ans = 0;
        int num = 0;
        post_trav(root, num, ans);
        
        return ans;
    }
};