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
    int deepestLeavesSum(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        
        int sum = 0;
        
        while(q.empty()==false)
        {
            vector<int> level;
            int count = 0;
            int size = q.size();
            
            for(int i=0;i<size;i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                    count++;
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                    count++;
                }
                
                level.push_back(temp->val);
            }
            
            if(count == 0)
            {
                sum = accumulate(level.begin(),level.end(),0);
                break;
            }
        }
        
        return sum;
    }
};