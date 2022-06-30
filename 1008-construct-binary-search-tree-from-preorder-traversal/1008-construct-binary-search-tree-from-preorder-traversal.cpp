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
    TreeNode* buildTree(vector<int>& pre, int start, int end){
        if(start>end) return NULL;
        TreeNode* root = new TreeNode(pre[start]);
        int x = start;
        while(x < end && pre[x+1]<=pre[start]) x++;
        root->left = buildTree(pre,start+1,x);
        root->right = buildTree(pre, x+1, end);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& pre) {
        return buildTree(pre,0,pre.size()-1);
    }
};