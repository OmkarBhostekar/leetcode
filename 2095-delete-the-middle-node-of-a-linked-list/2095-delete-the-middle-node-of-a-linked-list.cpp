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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *fast=head, *slow=head, *prev=NULL;
        while(fast->next && fast->next->next) fast = fast->next->next, prev = slow, slow = slow->next;
        if(fast->next) prev=slow, slow = slow->next;
        if(prev) prev->next = slow->next;
        else head = slow->next;
        delete slow;
        return head;
    }
};