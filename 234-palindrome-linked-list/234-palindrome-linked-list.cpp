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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* slow=head, *fast = head;
        st.push(slow->val);
        while(fast->next && fast->next->next){
            slow = slow->next;
            st.push(slow->val);
            fast = fast->next->next;
        }
        if(!fast->next){
            st.pop();
        }
        slow = slow->next;
        while(slow && !st.empty()){
            if(st.top() != slow->val)
                return false;
            st.pop();
            slow = slow->next;
        }
        return st.empty() && !slow;
    }
};