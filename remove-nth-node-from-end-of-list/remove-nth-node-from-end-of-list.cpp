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
        ListNode* tmp=head;
        int count=0;
        
        while(tmp)
        {
            tmp=tmp->next;
            count++;
        }
        
        int node=count-n;
        
        if(node<1)
        {
            tmp=head->next;
            delete head;
            return tmp;
        }
        tmp=head;
        while(node!=1)
        {
            tmp=tmp->next;
            node--;
        }
        ListNode* found=tmp->next;
        tmp->next=found->next;
        
        delete found;
        
        return head;
        
    }
};