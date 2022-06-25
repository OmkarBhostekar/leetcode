/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool isLeft = true;
          vector<vector<int>> res;
          queue<TreeNode*> q;
        int len;
          if(!root) return res;
          q.push(root);

        while(!q.empty()){
            len = q.size();
            vector<int> v;
            for(int i=0;i<len;i++){
                auto top = q.front();
                q.pop();
                v.push_back(top->val);
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            if(!isLeft) reverse(v.begin(),v.end());
            isLeft = !isLeft;
            res.push_back(v);
        }
        return res;
    }
};