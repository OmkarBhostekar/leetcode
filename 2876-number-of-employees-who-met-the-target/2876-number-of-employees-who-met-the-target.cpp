class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int ans = 0; for(auto x: hours) if(x>=target) ans++; return ans;
    }
};