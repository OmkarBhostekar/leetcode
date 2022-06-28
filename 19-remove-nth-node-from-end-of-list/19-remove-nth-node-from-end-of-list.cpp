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
        vector<ListNode*> v;
        ListNode* temp = head;
        while(temp){
            v.push_back(temp);
            temp = temp->next;
        }
        int idx = v.size()-n;
        ListNode* node = v[idx];
        if(idx>0){
            ListNode* prev = v[idx-1];
            prev->next = node->next;
        }else{
            head = node->next;
        }
        node->next = NULL;
        delete node;
        return head;
    }
};