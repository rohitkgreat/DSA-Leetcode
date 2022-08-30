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
class Solution {
public:
    void helper(TreeNode* root,int cur,int &ans)
    {
        if(root==NULL)
            return;
        cur=cur*10+root->val;
        
        if(root->left==NULL && root->right==NULL)
            {ans+=cur;
             return;
            }
        helper(root->left,cur,ans);
        helper(root->right,cur,ans);
        
        return;
        
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return 0;
        int cur=0;
        int ans=0;
        
        helper(root,cur,ans);
        
        return ans;
    }
};