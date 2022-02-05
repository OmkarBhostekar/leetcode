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
    
    ListNode* mergeLists(ListNode* left, ListNode* right){
        ListNode* result = new ListNode(0);
        ListNode* temp = result;
        while(left != NULL or right != NULL){
            if(left == NULL){
                temp-> next = right;
                right = right->next;
            }
            else if(right == NULL){
                temp-> next = left;
                left = left->next;
            }
            else if(left->val < right->val){
                temp->next = left;
                left = left->next;
            }else{
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        return result->next;
    }
    
    
    ListNode* sortList(vector<ListNode*> lists, int start, int end){
        if(start >= end) return lists[start];
        int mid = start + (end-start) / 2;
        ListNode* sl = sortList(lists,start,mid);
        ListNode* sr = sortList(lists,mid+1,end);
        return mergeLists(sl,sr);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        return sortList(lists,0,lists.size()-1);
    }
};