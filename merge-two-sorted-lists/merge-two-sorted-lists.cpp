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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1==NULL && l2==NULL)
            return NULL;
        
        ListNode* head=new ListNode;
        ListNode* tmp=NULL;
        bool first=false;
        
        while(l1 && l2)
        {
     
            if(l1->val <= l2->val)
            {
                if(first==false)
                {
                    head->val=l1->val;
                    head->next=NULL;
                    tmp=head;
                    first=true;
                    // continue;
                }
                else{
                ListNode* emp=new ListNode(l1->val);
                tmp->next=emp;
                tmp=emp;}
            l1=l1->next;
            }
            else
            {
                if(first==false)
                {
                    head->val=l2->val;
                    head->next=NULL;
                    tmp=head;
                    first=true;
                    // continue;
                }
                else{
                ListNode* emp=new ListNode(l2->val);
                tmp->next=emp;
                tmp=emp;
                }
                l2=l2->next;
            }
            
        }
        if(l1)
            {
                if(tmp)
                tmp->next=l1;
                else
                head=l1;
            }
        else
           {if(tmp) 
            tmp->next=l2;
            else
            head=l2;
           }
    
        return head;
    }
};