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
   
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)
            return head;
        if(head->next==NULL)
            return head;
        ListNode* frst=head;
        ListNode* scnd=head->next;
        
        ListNode* prev=NULL;
        bool hd=false;
        while(frst)
        {
            ListNode* temp=scnd->next;
            frst->next=temp;
            scnd->next=frst;
            
            if(prev)
                prev->next=scnd;
            if(hd==false)
               { head=scnd;
                    hd=true;
               }
                
            prev=frst;
            frst=frst->next; 
            if(frst==NULL || frst->next==NULL)
                return head;
            scnd=frst->next;
            
        }
        return head;
    }
};