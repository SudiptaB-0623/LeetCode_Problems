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
    void pre(TreeNode *root, stack<TreeNode*> &s1, stack<TreeNode*> &s2, int &ans)
    {
        if(root==NULL)
            return;
        
        s1.push(root);
        if(s2.empty())
        {
            s2.push(root);
            ans++;
        }
        else
        {
            TreeNode *temp = s2.top();
            if(temp->val>root->val)
                s2.push(temp);
            else
                s2.push(root);
            
            temp = s2.top();
            if(temp->val == root->val)
                ans++;
        }
        
        pre(root->left, s1, s2, ans);
        pre(root->right, s1, s2, ans);
        
        s1.pop();
        s2.pop();
    }
    
    int goodNodes(TreeNode* root) 
    {
        stack<TreeNode*> s1, s2;
        int ans = 0;
        
        pre(root, s1, s2, ans);
        
        return ans;
    }
};