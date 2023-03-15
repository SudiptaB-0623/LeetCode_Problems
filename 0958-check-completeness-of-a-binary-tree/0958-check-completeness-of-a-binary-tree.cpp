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
    bool isCompleteTree(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        int flag = 0;
        
        while(q.empty()==false)
        {
            int size = q.size();
                        
            for(int i=0;i<size;i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                
                //cout<<temp->val<<" ";
                
                if(temp->left==NULL && temp->right!=NULL)
                    return false;
                
                if(flag==1 && (temp->left!=NULL || temp->right!=NULL))
                   return false;
                
                if((temp->left==NULL && temp->right==NULL)  || (temp->left!=NULL && temp->right==NULL))              
                    flag = 1; 
                
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
            }
            //cout<<endl;
        } 
        return true;
    }
                   
};