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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2,ans;
        int carry=0, sum=0;
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }
        while(!s1.empty() or !s2.empty()){
            sum=carry;
            if(!s1.empty()){
                sum += s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                sum += s2.top();
                s2.pop();
            }
            carry = sum/10;
            sum %= 10;
            ans.push(sum);
        }
        if(carry) ans.push(carry);
        ListNode* dummy = new ListNode(0);
        ListNode* cur=dummy;
        while(!ans.empty()){
            cur->next = new ListNode(ans.top());
            cur = cur->next;
            ans.pop();
        }
        return dummy->next;
    }
};