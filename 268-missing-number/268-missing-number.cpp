class Solution {
public:
    long getTotal(int n){
        long s=0;
        for(int i=0;i<=n;i++)
            s+=i;
        return s;
    }
    
    int missingNumber(vector<int>& nums) {
        long total=0;
        for(int x: nums)
            total+=x;
        return (int) getTotal(nums.size()) - total;
    }
};