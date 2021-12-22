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
class BSTIterator {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    
    BSTIterator(TreeNode* root) {
        doit(root,pq);
        
    }
    
    int next() {
        int x=pq.top();
        pq.pop();
        return x;
    }
    
    bool hasNext() {
        return !pq.empty();
    }
    
    void doit(TreeNode* root,priority_queue<int,vector<int>,greater<int>> &pq)
    {
        if(root==NULL)
            return;
        
        doit(root->left,pq);
        pq.push(root->val);
        doit(root->right,pq);
    }      
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */