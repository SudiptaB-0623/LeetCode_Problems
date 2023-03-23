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
    bool isCousins(TreeNode* root, int x, int y) 
    {
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        
        while(q.empty()==false)
        {
            int size = q.size();
            int flag = 0;
            
            for(int i=0;i<size;i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
                if(node->left!=NULL && node->right!=NULL)
                {
                    if((node->left->val==x || node->left->val==y) && (node->right->val==x || node->right->val==y))
                    //if(node->left->val==(x||y) && node->right->val==(x||y))
                        return false;
                }
                if(node->val == x || node->val == y)
                {
                    if(flag == 1)
                    {
                        return true;
                    }
                    else
                    {
                        if(depth<=1)
                            return false;
                        else
                            flag = 1;
                            
                    }
                }
            }
            depth++;
        }
        
        return false;
    }
};