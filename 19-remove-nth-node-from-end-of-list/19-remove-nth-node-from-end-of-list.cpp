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
        if(!head || n==0) return head;
        ListNode *slow=head, *fast=head, *prev = NULL;
        for(int i=0;i<n;i++) fast = fast->next;
        while(fast){
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if(slow == head){
            head = slow->next;
        }else{
            prev->next = slow->next;
            delete slow;
        }
        return head;
    }
};