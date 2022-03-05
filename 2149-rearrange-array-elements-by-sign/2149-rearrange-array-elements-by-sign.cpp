class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> p;
        vector<int> n;
        for(int x: nums){
            if(x<0)
                n.push_back(x);
            else
                p.push_back(x);
        }
        nums.clear();
        for(int i=0; i<p.size(); i++){
            nums.push_back(p[i]);
            nums.push_back(n[i]);
        }
        return nums;
    }
};