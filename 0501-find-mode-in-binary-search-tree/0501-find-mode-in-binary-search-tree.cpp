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
    void inord(TreeNode *root, int &max, map<int, int> &mpp)
    {
        if(root==NULL)
            return;
        
        inord(root->left, max, mpp);
        mpp[root->val]++;
        if(mpp[root->val]>max)
            max = mpp[root->val];
        inord(root->right, max, mpp);
    }
    vector<int> findMode(TreeNode* root) 
    {
        int max= 0;
        map<int, int> mpp;
        inord(root, max, mpp);
        vector<int> ans;
        for(auto it: mpp)
        {
            if(it.second == max)
                ans.push_back(it.first);
        }
        return ans;
    }
};