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
    int preind=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int start=0;
        // int preind=0;
        
        return helper(preorder,inorder,start,preorder.size()-1);
        
        
    }
    
    TreeNode* helper(vector<int> preorder,vector<int> inorder,int start,int end)
    {
        if(start>end)
            return NULL;
        
        TreeNode* head=new TreeNode(preorder[preind++]);
        
        int pos;
        
        for(int i=start;i<=end;i++)
        {
            if(head->val==inorder[i])
               { pos=i;
                break;
               }
        }
        
        head->left=helper(preorder,inorder,start,pos-1);
        head->right=helper(preorder,inorder,pos+1,end);
        
        return head;
    }
};