class Solution {
public:
    int EQUAL = 0, INC=1, DEC=-1;
    int wiggleMaxLength(vector<int>& nums) {
        int len=1;
        int n = nums.size();
        int prev = EQUAL;
        for(int i=1;i<n;i++){
            int curr;
            if(nums[i] == nums[i-1])
                curr = EQUAL;
            else if(nums[i]>nums[i-1])
                curr = INC;
            else
                curr = DEC;
            if(prev != curr && curr != EQUAL){
                len++;
                prev = curr;
            }
        }
        return len;
    }
};