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
    void helper(ListNode* &head,ListNode* tmp)
    {
        if(head==NULL)
            return;
            
        ListNode* emp=head->next;
        head->next=tmp;
        tmp=head;
        
        if(emp==NULL)
            return;
        else
            head=emp;
        
        helper(head,tmp);
        
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* tmp=NULL;
      helper(head,tmp);
        return head;
        
    }
};