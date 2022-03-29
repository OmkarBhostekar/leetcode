class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        bool seen[100000+1]{0};
        for(int x: nums){
            if(seen[x]){
                return x;
            }
            seen[x] = true;
        }
        return -1;
    }
};