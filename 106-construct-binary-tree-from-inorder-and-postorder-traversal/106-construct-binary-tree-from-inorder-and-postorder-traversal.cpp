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
    int postin=0;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder,postorder,0,postorder.size()-1);
    }
    
    TreeNode* helper(vector<int>& in,vector<int> po,int start,int end)
    {
        if(start>end)
            return NULL;
        
        TreeNode* head=new TreeNode(po[po.size()-1-postin++]);
        int pos;
        
        for(int i=start;i<=end;i++)
        {
            if(in[i]==head->val)
            {
                pos=i;
                break;
            }
        }
        
        head->right=helper(in,po,pos+1,end);
        head->left=helper(in,po,start,pos-1);
        
        return head;
        
    }
};