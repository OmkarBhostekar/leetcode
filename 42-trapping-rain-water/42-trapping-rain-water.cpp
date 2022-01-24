class Solution {
public:
    int trap(vector<int>& h) {
        
        int ans = 0;
        int l = 0;
        int r = h.size()-1;
        int ml = 0;
        int mr = 0;
        while(l < r){
            if(h[l] <= h[r]){
                if(h[l]>ml) ml = h[l];
                else ans += ml - h[l];
                l++;
            }else{
                if(h[r]>mr) mr = h[r];
                else ans += mr - h[r];
                r--;
            }
        }
        return ans;
    }
};