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
    
    vector<TreeNode*> allPossibleFBT(int n) {
    
        vector<TreeNode*> ans;
        if(n==0)
            return ans;
        if(n==1)
        {
            TreeNode* head=new TreeNode(0);
            ans.push_back(head);
            
            return ans;
        }
        for(int i=1;i<n;i+=2)
        {
            vector<TreeNode*> left=allPossibleFBT(i);
            vector<TreeNode*> right=allPossibleFBT(n-i-1);
            
            for(int j=0;j<left.size();j++)
            {
                for(int k=0;k<right.size();k++)
                {
                    TreeNode* head=new TreeNode(0);
                    head->left=left[j];
                    head->right=right[k];
                    ans.push_back(head);
                }
            }
            
        }
        
        return ans;
        
    }
};