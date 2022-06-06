class Solution {
public:
    bool getPath(vector<int>& nums, vector<int>& v, int i){
        // if(i<0) return false;
        if(i>=nums.size()-1) return true;
        if(v[i]) return false;
        v[i] = 1;
        for(int j=1;j<=nums[i];j++){
            if(getPath(nums,v,i+j))
                return true;
            // if(getPath(nums,v,i-j))
            //     return true;
        }
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        vector<int> v(nums.size(),0);
        return getPath(nums,v,0);
    }
};