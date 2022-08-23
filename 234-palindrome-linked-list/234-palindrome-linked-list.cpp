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
    bool isPalindrome(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev=slow;
        slow=slow->next;
        prev->next=NULL;
        ListNode* temp;
        while(slow)
        {
            temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;            
        }
        
        fast=head,slow=prev;
        while(slow)
        {
            int x=fast->val;
            int y=slow->val;
            if(x!=y)
            {
                return false;
            }
            fast=fast->next;
            slow=slow->next;
        }
        return true;
    }
};