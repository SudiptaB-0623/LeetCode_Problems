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
    void pre(TreeNode *root, int target, vector<vector<int>> &ans, vector<int> &path, int &sum)
    {
        if(root==NULL)
            return;
        
        sum += root->val;
        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            if(sum==target)
                ans.push_back(path);
        }
        pre(root->left, target, ans, path, sum);
        pre(root->right, target, ans, path, sum);
        sum -= root->val;
        path.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<int> path;
        vector<vector<int>> ans;
        int sum = 0; 
        pre(root, targetSum, ans, path, sum);
        
        return ans;
    }
};