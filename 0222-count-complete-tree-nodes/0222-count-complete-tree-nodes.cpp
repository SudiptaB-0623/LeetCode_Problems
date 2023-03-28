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
    int countNodes(TreeNode* root) 
    {
        int sum = 0;
        if(root==NULL)
            return sum;
        stack<TreeNode*> s1, s2;
        s1.push(root);
        
        while(!s1.empty())
        {
            sum++;
            TreeNode *temp = s1.top();
            s1.pop();
            s2.push(temp);
            
            if(temp->left!=NULL)
                s1.push(temp->left);
            if(temp->right!=NULL)
                s1.push(temp->right);
        }
        
        return sum;
    }
};