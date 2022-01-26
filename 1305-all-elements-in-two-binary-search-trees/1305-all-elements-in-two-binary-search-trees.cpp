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
    void inOrderTraversal(TreeNode* root, vector<int> &v){
        if(root == NULL) return;
        inOrderTraversal(root->left,v);
        v.push_back(root->val);
        inOrderTraversal(root->right,v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        vector<int> v1,v2;
        inOrderTraversal(root1,v1);
        inOrderTraversal(root2,v2);
        int a=0,b=0;
        while(a<v1.size() and b<v2.size()){
            if(v1[a] < v2[b]){
                ans.push_back(v1[a]);
                a++;
            }else{
                ans.push_back(v2[b]);
                b++;
            }
        }
        while(a<v1.size()){
            ans.push_back(v1[a]);
            a++;
        }
        while(b<v2.size()){
            ans.push_back(v2[b]);
            b++;
        }
        return ans;
    }
};