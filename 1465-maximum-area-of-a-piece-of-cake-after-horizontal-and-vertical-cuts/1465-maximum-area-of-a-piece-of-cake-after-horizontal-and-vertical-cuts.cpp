class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        int MOD = 1000000000+7;
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        hc.insert(hc.begin(),0);
        vc.insert(vc.begin(),0);
        if(hc.back() != h) hc.push_back(h);
        if(vc.back() != w) vc.push_back(w);
        int max_h=0,max_w=0;
        for(int i=1;i<hc.size();i++){
            max_h = max(max_h,abs(hc[i]-hc[i-1]));
        }
        for(int j=1;j<vc.size();j++){
            max_w = max(max_w,abs(vc[j]-vc[j-1]));
        }
        long long int ans = ((long long)(max_h%MOD) *( max_w%MOD))%MOD;
        return ans;
    }
};