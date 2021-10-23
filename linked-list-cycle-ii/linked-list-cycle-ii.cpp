/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL || head->next==NULL)
            return NULL;
        
        ListNode* a=head;
        ListNode* b=head;
        
        do
        {
            if(b==NULL || b->next==NULL)
                return NULL;
            b=b->next->next;
            a=a->next;
                    
        }while(a!=b);
       
    
        a=head;
        while(a!=b)
        {
            a=a->next;
            b=b->next;
        }
        
        return b;
    }
};