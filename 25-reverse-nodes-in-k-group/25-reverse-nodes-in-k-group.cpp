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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> v;
        ListNode* temp = head;
        while(temp){
            v.push_back(temp->val);
            temp = temp->next;
        }
        int j = v.size()/k;
        for(int i=0;i<j;i++){
            reverse(v.begin()+(i*k),v.begin()+(i*k)+k);
        }
        temp = head;
        j=0;
        while(temp){
            temp->val = v[j++];
            temp = temp->next;
        }
        return head;
    }
};