class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nn, int target) {
        vector<long long> nums;
        for(auto x: nn) nums.push_back(x);
        int n = nums.size();
        if(n==0) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            long long target3 = (long long)target-(long long)nums[i];
            for(int j=i+1; j<n; j++){
                long long target2 = (long long) target3 - (long long)nums[j];
                int front = j+1, back = n-1;
                while(front<back){
                    long long two_sum = nums[front]+nums[back];
                    if(two_sum<target2) front++;
                    else if(two_sum > target2) back--;
                    else{
                        vector<int> v = { (int) nums[i], (int)nums[j],(int) nums[front], (int)nums[back] };
                        ans.push_back(v);
                        while(front < back && v[2] == nums[front]) ++front;
                        while(front < back && v[3] == nums[back]) --back;
                    }
                }
                
                while(j+1<n && nums[j] == nums[j+1]) ++j;
            }
            while(i+1<n && nums[i] == nums[i+1]) ++i;
        }
        return ans;
    }
};