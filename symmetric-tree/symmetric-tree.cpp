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
    
    
    void helper(TreeNode* q, TreeNode* p,bool &ans)
    {
        if(p==NULL && q==NULL)
            return;
        if(p==NULL && q || q==NULL && p)
           { ans=false;
           return;
           }
        
        if(p->val!=q->val)
            ans=false;
        helper(q->left,p->right,ans);
        helper(q->right,p->left,ans);
    }
    bool isSymmetric(TreeNode* root) {
        
        bool ans=true;
        
        helper(root->left,root->right,ans);
        return ans;
        
    }
};