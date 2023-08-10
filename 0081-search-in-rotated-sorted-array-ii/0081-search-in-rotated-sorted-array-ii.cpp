class Solution {
public:
    bool search(vector<int>& v, int t) {
        int l=0, r=v.size()-1;
        while(l<=r){
            int mid = l + (r-l) / 2;
            if(v[mid] == t) return true;
            if(v[l]==v[mid] && v[mid]==v[r]){
                l++;
                r--;
            }else if(v[l]<=v[mid]){
                if((v[l] <= t) && v[mid]>t){
                    r = mid-1;
                }else l = mid+1;
            }else{
                if((v[mid]<t) && v[r]>=t){
                    l = mid+1;
                }else r = mid-1;
            }
        }
        return false;
    }
};