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
    int findBottomLeftValue(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        
        int ans;
        while(!q.empty())
        {
            int sz=q.size();
            vector<int> temp;
            while(sz--)
            {
                TreeNode* fnt=q.front();
                q.pop();
                
                temp.push_back(fnt->val);
                
                if(fnt->left)
                    q.push(fnt->left);
                if(fnt->right)
                    q.push(fnt->right);
                
                
            }
            if(temp.size())
                ans=temp[0];
        }
        
        return ans;
        
    }
};