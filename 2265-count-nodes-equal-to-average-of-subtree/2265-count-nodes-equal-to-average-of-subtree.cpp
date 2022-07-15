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
    
    int sum(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int l=sum(root->left);
        int r=sum(root->right);
        
        return root->val+l+r;
    }
    int count(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int l=count(root->left);
        int r=count(root->right);
        
        return 1+l+r;
    }
    int helper(TreeNode* root)
    {
        if(root==NULL)
            return 0;
    
        int x=sum(root->left);
        int y=sum(root->right);
        int x1=count(root->left);
        int y1=count(root->right);
        
        int ans=(root->val+x+y)/(x1+y1+1);          
        if(ans==root->val)
            return helper(root->left)+helper(root->right)+1;
        return helper(root->left)+helper(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        return helper(root);
    }
};