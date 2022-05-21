/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       
     unordered_map<Node*,Node*>mp;
     unordered_map<Node*,Node*>mp2;
        
        if(head==NULL)
            return NULL;
        Node* head2=new Node(head->val);
        mp.insert({head,head2});
        mp2.insert({head,head->random});
        
        Node* temp=head;
        Node* temp2=head2;
        temp=temp->next;
        
        while(temp!=NULL)
        {
            Node *fr=new Node(temp->val);
            temp2->next=fr;
            mp2.insert({temp,temp->random});
            mp.insert({temp,fr});
            temp2=temp2->next;
            temp=temp->next;
            
        }
        temp2->next=NULL;
        
        temp2=head2;
        temp=head;
        
        while(temp)
        {
            temp2->random=mp[mp2[temp]];
            temp=temp->next;
            temp2=temp2->next;
        }
        
        
        
        
        return head2;
        
        
    }
};