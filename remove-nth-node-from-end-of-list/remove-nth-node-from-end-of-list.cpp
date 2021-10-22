/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
            return head;
        if(head->next==NULL && n==1)
            return NULL;
        ListNode* a=head;
        ListNode* b=head;
        ListNode* c=NULL;
        int count=1;
        
        while(count!=n)
        {
            a=a->next;
            count++;
        }
        
        while(a->next!=NULL)
        {   c=b;
            a=a->next;
            b=b->next;
        }
        
        if(c==NULL)
            head=head->next;
        else
        c->next=b->next;
        
        return head;
        
    }
};