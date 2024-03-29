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
    vector<TreeNode*> allPossibleBST(int start, int end, map<pair<int, int>, vector<TreeNode*>>& memo) 
    {
        vector<TreeNode*> ans;
        if (start > end) 
        {
            ans.push_back(nullptr);
            return ans;
        }
        if (memo.find(make_pair(start, end)) != memo.end()) 
        {
            return memo[make_pair(start, end)];
        }
        
        for (int i = start; i <= end; ++i) 
        {
            vector<TreeNode*> leftSubTrees = allPossibleBST(start, i - 1, memo);
            vector<TreeNode*> rightSubTrees = allPossibleBST(i + 1, end, memo);

            
            for (auto l: leftSubTrees) 
            {
                for (auto r: rightSubTrees) 
                {
                    TreeNode* root = new TreeNode(i, l, r);
                    ans.push_back(root);
                }
            }
        }
        return memo[make_pair(start, end)] = ans;
    }

    vector<TreeNode*> generateTrees(int n) 
    {
        map<pair<int, int>, vector<TreeNode*>> memo;
        return allPossibleBST(1, n, memo);
    }
};