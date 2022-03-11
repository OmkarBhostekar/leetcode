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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL or head->next == NULL)
            return head;
        if(head->val != head->next->val){
            head->next = deleteDuplicates(head->next);
            return head;
        }
        while(head->next != NULL and head->val == head->next->val)
              head = head->next;
        return deleteDuplicates(head->next);
    }
};