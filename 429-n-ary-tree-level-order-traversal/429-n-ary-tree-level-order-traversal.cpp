/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> ans;
        if(!root) return ans;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            vector<int> temp;
            while(len--){
                auto x = q.front();
                q.pop();
                temp.push_back(x->val);
                for(auto y: x->children){
                    q.push(y);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};