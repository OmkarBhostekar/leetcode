/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* itr = head;
        Node* front = head;
        while(itr != NULL){
            front = itr->next;
            Node* pnode = new Node(itr->val);
            itr->next = pnode;
            pnode->next = front;
            itr = front;
        }
        itr = head;
        while(itr != NULL){
            if(itr->random != NULL){
                itr->next->random = itr->random->next;   
            }
            itr = itr->next->next;
        }
        itr = head;
        Node* dummy = new Node(INT_MIN);
        Node* copy = dummy;
        while(itr != NULL){
            front = itr->next->next;
            copy->next = itr->next; 
            itr->next = front;
            copy = copy->next;
            itr = itr->next;
        }
        return dummy->next;
    }
};