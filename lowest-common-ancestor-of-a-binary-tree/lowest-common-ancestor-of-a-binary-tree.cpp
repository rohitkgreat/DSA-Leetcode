/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(TreeNode* root,TreeNode* p,TreeNode* q)
    {
       if(root==NULL || root==p || root==q)
           return root;
        
        TreeNode* lt=helper(root->left,p,q);
        TreeNode* rt=helper(root->right,p,q);
        
        if(lt==NULL)
            return rt;
        if(rt==NULL)
            return lt;
        
        return root;
           
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* temp=NULL;
        return helper(root,p,q);
        
    }
};