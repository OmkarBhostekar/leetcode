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
    ListNode* rec(ListNode* head, int i, int n, int &ans){
        if(i==n){
            ans = max(ans,(head->val + head->next->val));
            return head->next->next;
        }
        ListNode* next = rec(head->next,i+1,n,ans);
        int x = head->val + next->val;
        ans = max(ans,x);
        return next->next;
    }
    
    int pairSum(ListNode* head) {
        int ans =0,n=0;
        ListNode* temp = head;
        while(temp) n++, temp = temp->next;
        rec(head,1,n/2,ans);
        return ans;
    }
};