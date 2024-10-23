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
    TreeNode* replaceValueInTree(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> levelSums;

        while(!q.empty()) 
        {
            int levelSum = 0;
            int levelSize = q.size();
            for (int i=0; i<levelSize; i++) 
            {
                TreeNode* curr = q.front();
                q.pop();
                levelSum += curr->val;
                if (curr->left != NULL) 
                    q.push(curr->left);
                if (curr->right != NULL) 
                    q.push(curr->right);
            }
            levelSums.push_back(levelSum);
        }

        q.push(root);
        int levelIndex = 1;
        root->val = 0;  
        while(!q.empty()) 
        {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) 
            {
                TreeNode* curr = q.front();
                q.pop();

                int siblingSum = (curr->left ? curr->left->val : 0) + (curr->right ? curr->right->val : 0);

                if (curr->left != NULL) 
                {
                    curr->left->val = levelSums[levelIndex] - siblingSum;
                    q.push(curr->left);
                }
                if (curr->right != NULL) 
                {
                    curr->right->val = levelSums[levelIndex] - siblingSum;
                    q.push(curr->right);
                }
            }
            levelIndex++;
        }

        return root;
    }
};