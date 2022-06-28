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
    ListNode* mergeNodes(ListNode* head) {
        if(!head || !head->next) return NULL;
        if(!head->next->next) return head->next;
        ListNode* prev = head->next, *cur = prev->next, *dup;
        while(cur && cur->val != 0){
            prev->val += cur->val;
            dup = cur;
            cur = cur->next;
            delete dup;
        }
        prev->next = mergeNodes(cur);
        return prev;
    }
};