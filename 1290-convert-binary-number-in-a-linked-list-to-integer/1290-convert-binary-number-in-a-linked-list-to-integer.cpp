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
    int getDecimalValue(ListNode* head) {
        vector<int> v;
        int size = 0;
        ListNode* temp = head;
        int ans = 0;
        while(temp != NULL){
            size++;
            v.push_back(temp->val);
            temp = temp->next;
        }
        for(int i=0; i<size; i++){
            int x = v[i];
            if(x == 1){
                ans += pow(2,size-i-1);
            }
        }
        return ans;
    }
};