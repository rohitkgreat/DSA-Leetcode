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
    int helper(TreeNode* root,int &maxx)
    {
        if(root==NULL)
            return 0;
        
        int h1=helper(root->left,maxx);
        int h2=helper(root->right,maxx);
        
        maxx=max(maxx,h1+h2);
        
        return 1+max(h1,h2);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        int maxx=0;
       
         helper(root,maxx);
        return maxx;
    }
};