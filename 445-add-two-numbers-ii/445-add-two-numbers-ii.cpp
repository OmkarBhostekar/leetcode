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
    ListNode* reverse(ListNode* head){
        ListNode* cur = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(cur){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0, sum=0;
        ListNode* dummy = new ListNode(0);
        ListNode* cur=dummy;
        l1 = reverse(l1);
        l2 = reverse(l2);
        while(l1 or l2 or carry){
            sum=carry;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum/10;
            sum %= 10;
            cur->next = new ListNode(sum);
            cur = cur->next;
        }
        return reverse(dummy->next);
    }
};