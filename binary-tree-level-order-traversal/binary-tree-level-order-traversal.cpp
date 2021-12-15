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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
    vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        

        queue<TreeNode*>q;
        q.push(root);
        vector<int> temp;
        while(!q.empty())
        {
            
            int sz=q.size();
          
            
            while(sz--)
            {
                TreeNode* frnt=q.front();
                q.pop();
                
                temp.push_back(frnt->val);
                
                if(frnt->left)
                    q.push(frnt->left);
                if(frnt->right)
                    q.push(frnt->right);
            }
            if(temp.size())
            ans.push_back(temp);
            
            temp.clear();
        }
        return ans;
        
    }
};