// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
class Solution{
public:

    TreeNode* buildBST(vector<int>& nums, int start, int end){
        if(start>end) return NULL;
        int mid = start + ((end-start)/2);
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildBST(nums, start, mid-1);
        root->right = buildBST(nums, mid+1, end);
        return root;
    }

    void preOrder(TreeNode* root, vector<int> &ans){
        if(!root) return;
        ans.push_back(root->val);
        preOrder(root->left,ans);
        preOrder(root->right,ans);
    }

    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        TreeNode* root = buildBST(nums,0,nums.size()-1);
        vector<int> ans;
        preOrder(root, ans);
        return ans;
    }
    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends