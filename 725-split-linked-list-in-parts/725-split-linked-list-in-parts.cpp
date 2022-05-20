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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
       
        int count=0;
        ListNode* temp=head;
        
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        
        int z=count/k;
        int y=count%k;
        
        temp=head;
        
        for(int i=0;i<y;i++)
        {
            ListNode* fnt=temp;
            int zz=z;
            while(temp!=NULL && zz--)
            temp=temp->next;
            
            ListNode* tmp=temp;
            if(tmp){
                temp=temp->next;
                tmp->next=NULL;
            }
                
            ans.push_back(fnt);
        }
        
        int m=ans.size();
        int diff=k-m;
        
        for(int i=0;i<diff;i++)
        {
            ListNode* fnt=temp;
            int zz=z-1;
            while(temp!=NULL && zz--)
                temp=temp->next;
            
            ListNode* tmp=temp;
            if(tmp)
                {
                temp=temp->next;
                tmp->next=NULL;
            }
            ans.push_back(fnt);
        }
        
        return ans;
    }
};