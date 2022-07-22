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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        vector<ListNode*> v;
        ListNode* prev = dummy, *temp = head;
        while(temp != NULL){
            if(temp->val < x){
                v.push_back(temp);
                prev->next = temp->next;
                temp = temp->next;
            }else{
                prev = temp;
                temp = temp->next;
            }
        }
        if(v.empty()) return dummy->next;
        prev = v[0];
        for(int i=1;i<v.size();i++){
            temp = v[i];
            prev->next = temp;
            prev = temp;
        }
        prev->next = dummy->next;
        return v[0];
    }
};