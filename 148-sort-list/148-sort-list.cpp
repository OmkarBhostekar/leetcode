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
    static bool compare(ListNode* a, ListNode* b){
        return a->val < b->val;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL or head->next == NULL) return head;
        vector<ListNode*> v;
        ListNode* temp = head;
        while(temp!=NULL){
            v.push_back(temp);
            temp = temp->next;
        }
        sort(v.begin(),v.end(),compare);
        for(int i=0; i<v.size(); i++){
            if(i+1<v.size()){
                v[i]->next = v[i+1];
            }else{
                v[i]->next = NULL;
            }
        }
        return v[0];
    }
};