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
    
    void left(TreeNode *root, vector<int> &lpart)
    {
        if(root == NULL)
            return;
 
        lpart.push_back(root->val);
        if(root->left!=NULL)
            left(root->left, lpart);
        else
            lpart.push_back(-101);
        if(root->right!=NULL)
            left(root->right, lpart);
        else
            lpart.push_back(-101);
    }
    void right(TreeNode *root, vector<int> &rpart)
    {
        if(root == NULL)
            return;

        rpart.push_back(root->val);
        if(root->right!=NULL)
            right(root->right, rpart);
        else
            rpart.push_back(-101);
        if(root->left!=NULL)
            right(root->left, rpart);
        else
            rpart.push_back(-101);
        
    }
    bool isSymmetric(TreeNode* root) 
    {
        vector<int> lpart, rpart;
        left(root->left, lpart);
        right(root->right, rpart);
        
        if(lpart.size()!=rpart.size())
            return false;
        
        for(int i=0;i<lpart.size();i++)
        {
            if(lpart[i]!=rpart[i])
                return false;
        }
        
        return true;
    }
};