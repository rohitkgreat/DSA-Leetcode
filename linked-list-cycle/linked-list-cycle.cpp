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
    bool hasCycle(ListNode *head) {
        
        if(head==NULL)
            return false;
       ListNode* start=head;
       ListNode* fast=head->next;
        
        if(start==NULL || fast==NULL)
            return false;
       
        while(start!=fast)
       {
           if(fast==NULL || fast->next==NULL)
               return false;
           
           fast=fast->next->next;
           start=start->next;
           
       }
      return true;
         
    }
};