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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)
            return head;
        
        vector<int> temp;
        ListNode* top=head;
        ListNode* s1;
        ListNode* s2;
        
        bool flag=false;
        
        int count=1;
        while(true)
        {
            if(count==left)
            {
                s1=top;
                flag=true;
            }
            if(flag)
                temp.push_back(top->val);
            
            if(count==right)
                break;
            count++;
            top=top->next;
        }
        
        while(true)
        {
            int x=temp.back();
            temp.pop_back();
            s1->val=x;
            s1=s1->next;
            
            if(temp.size()==0)
                break;
        }
        
        return head;
    }
};