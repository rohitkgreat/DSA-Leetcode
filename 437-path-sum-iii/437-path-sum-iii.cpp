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
    int count=0;
    void helper(TreeNode* root,long long target,bool take)
    {
       
        if(root==NULL)
           return;
        if(target-root->val==0)
           count++;
        if(take==false)
        {
            helper(root->left,target-root->val,true);
            helper(root->left,target,false);
            helper(root->right,target-root->val,true);
            helper(root->right,target,false);
            return;
        }
            helper(root->left,target-root->val,true);
            helper(root->right,target-root->val,true);
            
        
    }
        
    int pathSum(TreeNode* root, int targetSum) {
        helper(root,(long long)targetSum,false);
        return count;
    }
};