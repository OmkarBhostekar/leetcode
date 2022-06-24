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
    ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
        unordered_set<ListNode*> st;
        while(l1 && l2){
            if(l1 == l2) return l1;
            if(st.find(l1) != st.end()) return l1;
            if(st.find(l2) != st.end()) return l2;
            st.insert(l1);
            st.insert(l2);
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            if(st.find(l1) != st.end()) return l1;
            l1 = l1->next;
        }
        while(l2){
            if(st.find(l2) != st.end()) return l2;
            l2 = l2->next;
        }
        return NULL;
    }
};