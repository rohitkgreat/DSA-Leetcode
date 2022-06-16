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
   
    int helper(TreeNode* root,TreeNode* parent,map<pair<TreeNode*,TreeNode*>,int>&mp)
    {
        if(root==NULL)
            return 0;
        pair<TreeNode*,TreeNode*>temp;
        temp.first=root;
        temp.second=parent;
        
        int ans=INT_MIN;
        if(mp.find(temp)!=mp.end())
            return mp[temp];
        if(parent==NULL)
        {
            ans=helper(root->left,root,mp)+helper(root->right,root,mp)+root->val;
            ans=max(helper(root->left,NULL,mp)+helper(root->right,NULL,mp),ans);
            
            // return max(ans,ans2);
        }
        else
        {
            ans= helper(root->left,NULL,mp)+helper(root->right,NULL,mp);
           
        }
        mp[temp]=ans;
        return ans;
    }
    int rob(TreeNode* root) {
        map<pair<TreeNode*,TreeNode*>,int>mp;
        
        return helper(root,NULL,mp);     
    }
};