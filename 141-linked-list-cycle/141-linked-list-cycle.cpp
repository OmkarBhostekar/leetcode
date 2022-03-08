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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode *, int> mpp;
        int i=0;
        while(head != NULL){
            if(mpp[head] != 0){
                return true;
            }
            mpp[head] = i;
            head = head->next;
            i++;
        }
        return false;
    }
};