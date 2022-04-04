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
    ListNode* swapNodes(ListNode* head, int k) {
        int n=0;
        ListNode* temp = head;
        while(temp != NULL){
            n++;
            temp = temp->next;
        }
        int l = n-k+1;
        int i=1;
        temp = head;
        while(i<=n){
            if(i==min(k,l)){
                ListNode* first = temp;
                while(i<=n){
                    if(i==max(k,l)){
                        int t = temp->val;
                        temp->val = first->val;
                        first->val = t;
                        return head;
                    }
                    temp = temp->next;
                    i++;
                }
            }else
                temp = temp->next;
            i++;
        }
        return head;
    }
};