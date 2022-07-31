class SegmentTreeNode {
public:
    int start, end, sum=0;
    SegmentTreeNode* left, *right;
    SegmentTreeNode(int start, int end){
        this->start = start;
        this->end = end;
        left = NULL;
        right = NULL;
        sum = 0;
    }
};

class NumArray {
public:
    SegmentTreeNode *root = NULL;
    
    NumArray(vector<int>& nums) {
        root = buildTree(nums,0,nums.size()-1);
    }
    
    SegmentTreeNode* buildTree(vector<int> &nums, int start, int end){
        if(start>end) return NULL;
        SegmentTreeNode* ret = new SegmentTreeNode(start,end);
        if(start == end){
            ret->sum = nums[start];
        }else{
            int mid = start + (end-start)/2;
            ret->left = buildTree(nums,start,mid);
            ret->right = buildTree(nums,mid+1,end);
            ret->sum = ret->left->sum + ret->right->sum;
        }
        return ret;
    }
    
    void update(int i, int val) {
        updateHelper(root,i,val);
    }
    
    void updateHelper(SegmentTreeNode* ret, int i, int val){
        if(ret->start == ret->end){
            ret->sum = val;
        }else{
            int mid = ret->start + (ret->end - ret->start) / 2;
            if(i<=mid){
                updateHelper(ret->left, i, val);
            }else{
                updateHelper(ret->right, i, val);
            }
            ret->sum = ret->left->sum + ret->right->sum;
        }
    }
    
    int sumRange(int left, int right) {
        return sumRangeHelper(root, left, right);
    }
    
    int sumRangeHelper(SegmentTreeNode* ret, int start, int end){
        if(ret->end == end && ret->start == start){
            return ret->sum;
        }
        int mid = ret->start + (ret->end - ret->start) / 2;
        if(end<=mid){
            return sumRangeHelper(ret->left, start, end);
        }else if(start>=mid+1){
            return sumRangeHelper(ret->right, start, end);
        }else{
            return sumRangeHelper(ret->left, start, mid) + sumRangeHelper(ret->right, mid+1, end);
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */