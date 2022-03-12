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
        Node* temp = head;
        unordered_map<Node*,Node*> mpp;
        while(temp != NULL){
            Node* pnode = new Node(temp->val);
            mpp[temp] = pnode;
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL){
            if(temp->next == NULL){
                mpp[temp]->next = NULL;
            }else{
                mpp[temp]->next = mpp[temp->next];
            }
            if(temp->random == NULL){
                mpp[temp]->random = NULL;
            }else{
                mpp[temp]->random = mpp[temp->random];
            }
            temp = temp->next;
        }
        return mpp[head];
    }
};