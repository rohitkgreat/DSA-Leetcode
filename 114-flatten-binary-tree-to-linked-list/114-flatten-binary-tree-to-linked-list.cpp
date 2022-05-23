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
    void helper(TreeNode* root,vector<int> &ans)
    {
        if(root==NULL)
            return;
         ans.push_back(root->val);
        helper(root->left,ans);
        helper(root->right,ans);
       
        
    }
    void flatten(TreeNode* root) {
        
        if(root==NULL)
            return;
        vector<int> ans;
        helper(root->left,ans);
        helper(root->right,ans);
        
        int z=ans.size();
        
        root->left=NULL;
        TreeNode* temp=root;
        
        int i=0;
        while(i!=z)
        {
        if(temp->right==NULL)
        {
            TreeNode* tp=new TreeNode();
            temp->right=tp;
            tp->left=NULL;
            tp->right=NULL;
        }
        temp->left=NULL;
        temp=temp->right;
        temp->val=ans[i];
        i++;
            
        }
        
    }
};