/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    int idx=0;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        helper2(root,ans);
       
        return ans;
    }
    
    void helper2(TreeNode* root, string &ans)
    {
         if(root==NULL)
           { 
             ans+='#';
             return;
           }
        int x=root->val;
        string z=to_string(x);
        ans+=z;
        ans+=',';
        
        helper2(root->left,ans);
        helper2(root->right,ans);
        
        return;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n=data.length();
        if(n==0)
            return NULL;
        cout<<data<<endl;
        return helper(data,n);
    }
    
    TreeNode* helper(string data,int n)
    {
        
        if(data[idx]==',')
            idx++;
        // cout<<"idx "<<idx<<" ";
        if(data[idx]=='#'){
            idx++;
            return NULL;
        }
        string temp;
        while(idx+1<n && data[idx]!=',' && data[idx]!='#')
        {
            temp.push_back(data[idx]);
            idx++;
        }
                            // cout<<"string "<<temp<<endl;
        // int z=0;
        int z=stoi(temp);
        // cout<<z<<" "<<idx<<endl;
        TreeNode* node=new TreeNode(z);
        
        node->left=helper(data,n);
        // cout<<z<<" "<<idx<<endl;
        node->right=helper(data,n);
        
        return node;
        
        
    }
};
