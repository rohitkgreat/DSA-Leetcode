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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
//         if(headA==NULL || headB==NULL)
//             return NULL;
        
        
//         ListNode* a=headA;
//         ListNode* b=headB;
        
//         while(a!=b)
//         {
//             if(a==NULL)
//             a=headB;
//             else if(a!=NULL)
//                 a=a->next;
            
//             if(b==NULL)
//                 b=headA;
//             else if(b!=NULL)
//                 b=b->next;
            
            
//         }
        
//         return b;
        
        int count1=0,count2=0;
        ListNode* a=headA;
        ListNode* b=headB;
        
        while(a)
        {
            count1++;
            a=a->next;
        }
        
        while(b)
        {
            count2++;
            b=b->next;
        }
        a=headA;
        b=headB;
        
        if(count2>count1)
        {
            count2=count2-count1;
            
            while(count2--)
                b=b->next;
                             
        }
        else
        {
            count1=count1-count2;
            while(count1--)
                a=a->next;
        }
        
        while(a!=b)
        {
            a=a->next;
            b=b->next;
        }
        
        return b;
        
        
    }
};