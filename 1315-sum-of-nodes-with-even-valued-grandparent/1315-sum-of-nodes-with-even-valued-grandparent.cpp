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
    void calculateSum(TreeNode* root, int &ans, pair<int,int> p){
        if(root == NULL) return;
        if(p.first != 0 and p.first % 2 == 0){
            ans += root->val;
        }
        calculateSum(root->left,ans,{p.second,root->val});
        calculateSum(root->right,ans,{p.second,root->val});
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        calculateSum(root,ans,{0,0});
        return ans;
    }
};