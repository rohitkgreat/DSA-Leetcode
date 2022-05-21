/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void printnode(TreeNode*root,int k,vector<int>&ans){
        if(root==NULL){
            return ;
        }
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        printnode(root->left,k-1,ans);
        printnode(root->right,k-1,ans);
    }
    int helper(TreeNode* root, TreeNode* target, int k,vector<int>&ans,TreeNode*curr){
        if(curr==NULL){
            return -1;
        }
        if(curr==target){
//          it means we need to print all node to depth k from this node
            printnode(target,k,ans);
            return 1;
        }else{
            int ld=helper(root,target,k,ans,curr->left);
            int rd=helper(root,target,k,ans,curr->right);
            if(ld==k){
                ans.push_back(curr->val);
                return ld+1;
            }
            if(rd==k){
                ans.push_back(curr->val);
                return rd+1;
            }
            if(ld==-1 && rd==-1){
                return -1;
            }else if(ld!=-1) {
                printnode(curr->right,k-ld-1,ans);
                return ld+1;
            }else{
                printnode(curr->left,k-rd-1,ans);
                return rd+1;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        helper(root,target,k,ans,root);
        return ans;
    }
};