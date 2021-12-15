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
    
    int helper(TreeNode* root,bool &ans)
    {
        if(root==NULL)
            return 0;
        
        int x=1+helper(root->left,ans);
        int y=1+helper(root->right,ans);
        
        if(abs(x-y)>1)
            ans=false;
        
        return max(x,y);
            
    }
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        helper(root,ans);
        return ans;
    }
};