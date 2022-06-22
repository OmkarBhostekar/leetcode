class Solution {
public:
    int merge(vector<int>& nums, int start,int mid, int end){
        int i=start,j=mid+1,cnt=0;
        for(i=start; i<=mid; i++){
            while(j<=end and nums[i]>(2LL*nums[j])) j++;
            cnt += (j-(mid+1));
        }
        i=start,j=mid+1;
        vector<int> temp;
        while(i<=mid and j<=end){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i++]);
            }else{
                temp.push_back(nums[j++]);
            }
        }
        while(i<=mid){
            temp.push_back(nums[i++]);
        }
        while(j<=end){
            temp.push_back(nums[j++]);
        }
        for(int i=start;i<=end;i++){
            nums[i] = temp[i-start];
        }
        return cnt;
    }
    
    int mergeSort(vector<int>& nums, int start, int end){
        if(start == end) return 0;
        int mid = ((end+start)/2);
        int ans = mergeSort(nums, start, mid);
        ans += mergeSort(nums, mid+1, end);
        ans += merge(nums, start,mid, end);
        return ans;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};