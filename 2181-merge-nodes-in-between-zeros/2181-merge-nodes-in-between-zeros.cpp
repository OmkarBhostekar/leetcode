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
        ListNode *prev=head->next,*dup;
        if(!prev->next) return prev;
        ListNode *temp = prev->next;
        while(temp){
            while(temp && temp->val != 0){
                prev->val += temp->val;
                temp = temp->next;
            }
            prev->next = temp->next; // skip 0
            prev = prev->next;
            if(prev) temp = prev->next;
            else temp = prev;
        }
        return head->next;
    }
};