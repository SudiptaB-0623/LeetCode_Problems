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
    void pre(TreeNode *root, vector<string> &ans, string &path, int &len)
    {
        if(root==NULL)
            return;
        
        int temp;
        if(path.empty())
        {
            path = to_string(root->val);
            len = path.length();
        }
        else
        {
            path.append("->");
            path.append(to_string(root->val));
            temp = path.length()-len;
            len += temp;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
            //cout<<path<<endl;
            ans.push_back(path);
        }
        pre(root->left, ans, path, len);
        pre(root->right, ans, path, len);
        if(path.length()<temp)
        {
            path.erase();
        }
        else
        {
            len -= temp;
            path.erase(len); 
        }
        
        return;
    }    
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        string path = {};
        vector<string> ans;
        int len = 0;
        pre(root, ans, path, len);
        
        return ans;
    }
};