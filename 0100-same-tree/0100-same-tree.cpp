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
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        stack<pair<TreeNode*, TreeNode*>> stck;
        stck.push({p, q});
        while (!stck.empty()) 
        {
            auto [node1, node2] = stck.top();
            stck.pop();
            if (!node1 && !node2) continue;
            if (!node1 || !node2 || node1->val != node2->val) return false;
            stck.push({node1->left, node2->left});
            stck.push({node1->right, node2->right});
        }
        return true;
    }
};