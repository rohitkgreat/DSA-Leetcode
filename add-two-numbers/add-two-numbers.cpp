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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
//         if(l1==NULL)
//             return l2;
//         else if(l2==NULL)
//             return l1;
        
//         ListNode* a=l1;
//         ListNode* b=l2;
        
//         int carry=0;
//         int sm,flag=0,sum;
//         while(a!=NULL && b!=NULL)
//         {   
//             int x=a->val;
//             int y=b->val;
//             sum=x+y+carry;
            
//             if(sum>=10)
//             {
//                 carry=1;
//                 sm=sum%10;
//             }
//             else
//             {sm=sum;
//              carry=0;
//             }
            
//             a->val=sm;
//             a=a->next;
//             b=b->next;
             
           
           
            
//         }
        
//         if(a!=NULL)
//         {
//             while(a->next!=NULL)
//            { int z=a->val + carry;
            
//             if(z>=10)
//                 sm=z%10;
//             else
//             {
//                 carry=0;
//                 sm=z;
//             }
//             a->val=sm;
//             a=a->next;}
//         }
//         else if(b!=NULL)
//         {
//             sum=b->val+carry;
//             if(sum>=10)
//                 sm=sum%10;
//             else
//             {
//                 carry=0;
//                 sm=sum;
//             }
//              ListNode *node = new ListNode(sm); 
//              a->next=node;
//         }
//         if(carry==1)
//         {ListNode *node = new ListNode(1);
//          a->next=node;
//         }
//         return l1;
        ListNode *dummy = new ListNode(); 
        ListNode *temp = dummy; 
        int carry = 0;
        while( (l1 != NULL || l2 != NULL) || carry) {
            int sum = 0; 
            if(l1 != NULL) {
                sum += l1->val; 
                l1 = l1 -> next; 
            }
            
            if(l2 != NULL) {
                sum += l2 -> val; 
                l2 = l2 -> next; 
            }
            
            sum += carry; 
            carry = sum / 10; 
            ListNode *node = new ListNode(sum % 10); 
            temp -> next = node; 
            temp = temp -> next; 
        }
        return dummy -> next; 
    }
};