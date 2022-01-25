class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return false;
        bool dec = false;
        bool inc = false;
        for(int i=1;i<n;i++){
            if(arr[i-1]<arr[i]){
                if(dec) 
                    return false;
                inc = true;
            }else if(arr[i-1]>arr[i]){
                if(!inc)
                    return false;
                dec = true;
            }else{
                return false;
            }
        }
        return dec ;
    }
};