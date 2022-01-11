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
    int ans = 0;
    
    int getDec(string x){
        int a = 0;
        int b = 0;
        for(int i=x.length()-1; i>=0; i--){
            if(x[i] == '1')
                a += pow(2,b);
            b++;
        }
        return a;
    }
    
    void sumRoot(TreeNode* root,string x){
        x += to_string(root->val);
        if(root->left == NULL and root->right == NULL){
            ans += getDec(x);
            return;
        }
        if(root->left != NULL) sumRoot(root->left,x);
        if(root->right != NULL) sumRoot(root->right,x);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        sumRoot(root,"");
        return ans;
    }
};