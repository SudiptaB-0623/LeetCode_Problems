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
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        int lev = 0;
        
        while(!q.empty())
        {
            vector<int> level;
            stack<TreeNode*> st;
            int size = q.size();
            
            for(int i=0;i<size;i++)
            {
                TreeNode *curr = q.front();
                st.push(curr);
                q.pop();
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
                level.push_back(curr->val);
            }
            
            if(lev%2!=0)
            {
                for(int i=0;i<level.size();i++)
                {
                    TreeNode *curr = st.top();
                    st.pop();
                    curr->val = level[i];
                }
            }
            
            lev++;
        }
        
        return root;
    }
};