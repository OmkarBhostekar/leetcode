class Solution {
public:
    void shiftItem(vector<int>& nums, int i){
        int temp = nums[i];
        vector<int>::iterator it = nums.begin()+i;
        nums.erase(it);
        nums.push_back(temp);
    }
    
    int removeDuplicates(vector<int>& nums) {
        map<int,vector<int>> mpp;
        int count = 0;
        int s = 0;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]].push_back(i);
        }
        for(auto x: mpp){
            if(x.second.size() > 2){
                count += 2;
                for(int i=2; i<x.second.size(); i++){
                    shiftItem(nums,x.second[i]-s);
                    s++;
                }
            } else
                count += x.second.size();
        }
        return count;
    }
};