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
    TreeNode* helper(vector<int>& nums,int low,int high)
    {
        while(low<=high)
        {
            int mid=(low+high)/2;
            TreeNode* temp=new TreeNode(nums[mid]);
            temp->left=helper(nums,low,mid-1);
            temp->right=helper(nums,mid+1,high);
            
            return temp;
        }
        return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int low=0,high=nums.size()-1;
        
        return helper(nums,low,high);
    }
};