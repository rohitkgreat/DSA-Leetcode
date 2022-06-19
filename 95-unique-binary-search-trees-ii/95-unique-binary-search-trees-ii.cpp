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
    vector<TreeNode*> helper(int leftt,int rightt)
    {
        vector<TreeNode*> ans;        
        if(leftt>rightt)
           {ans.push_back(NULL); 
            return ans;}
        // if(n==1)
        // {
        //     TreeNode* root=new TreeNode(end);
        //     ans.push_back(root);
        //     return ans;
        // }
        
        for(int num=leftt;num<=rightt;num++)
        {
            
            vector<TreeNode*> left=helper(leftt,num-1);
            vector<TreeNode*> right=helper(num+1,rightt);
               
            
            for(int j=0;j<left.size();j++)
            {
                for(int k=0;k<right.size();k++)
                {
                    TreeNode* root=new TreeNode(num);
                    if(left.size())
                    root->left=left[j];
                    if(right.size())
                    root->right=right[k];
                    
                    ans.push_back(root);
                    // return ans;
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
       return helper(1,n);
    }
};