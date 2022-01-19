/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode *slow = head, *fast = head;
        do{
            // move slow by 1
            slow = slow->next;
            if(!slow) break;
            
            // move fast by 2
            fast = fast->next;
            if(!fast) break;
            fast = fast->next;
            if(!fast) break;
        }while(fast != slow);
        
        // no cycle
        if(!fast or !slow)
            return NULL;
        
        // check entry point
        fast = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};