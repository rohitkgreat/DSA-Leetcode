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
        
        ListNode* tmp=head;
        string ans="";
        while(tmp)
        {
            ans+=tmp->val;
            tmp=tmp->next;
        }
        int n=ans.size();
        for(int i=0;i<n/2;i++)
        {
            if(ans[i]!=ans[n-1-i])
            return false;
        }
        return true;
    }
};