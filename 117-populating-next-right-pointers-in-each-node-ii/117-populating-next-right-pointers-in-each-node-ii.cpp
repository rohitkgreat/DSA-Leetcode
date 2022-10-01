/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        queue<Node*> q;
        q.push(root);
        root->next=NULL;
        
        while(q.size())
        {
            queue<Node*> tmp;
            int z=q.size();
            
            while(z--)
            {
                Node* frt=q.front();
                q.pop();
                
                if(frt->left)
                {
                    q.push(frt->left);
                    tmp.push(frt->left);
                }
                if(frt->right)
                {
                    q.push(frt->right);
                    tmp.push(frt->right);
                }
            }
            if(tmp.size())
            {
                Node* a=tmp.front();
                tmp.pop();
                 
                while(!tmp.empty())
                {                    
                    Node* b=tmp.front();
                    tmp.pop();
                    a->next=b;
                    a=b;
                }
                a->next=NULL;
            }
        }
        return root;
    }
};